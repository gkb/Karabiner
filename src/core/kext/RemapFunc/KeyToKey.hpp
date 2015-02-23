#ifndef KEYTOKEY_HPP
#define KEYTOKEY_HPP

#include "RemapFuncBase.hpp"
#include "TimerWrapper.hpp"

namespace org_pqrs_Karabiner {
namespace RemapFunc {
class KeyToKey final : public RemapFuncBase {
public:
  static void static_initialize(IOWorkLoop& workloop);
  static void static_terminate(void);

  KeyToKey(void) : RemapFuncBase(BRIDGE_REMAPTYPE_KEYTOKEY),
                   index_(0),
                   currentToEvent_(CurrentToEvent::TO_KEYS),
                   keyboardRepeatID_(-1),
                   isRepeatEnabled_(true),
                   delayUntilRepeat_(-1),
                   keyRepeat_(-1) {}

  ~KeyToKey(void) {
    if (target_ == this) {
      fire_timer_.cancelTimeout();
      target_ = NULL;
    }
  }

  void prepare(RemapParams& remapParams) override;
  bool remap(RemapParams& remapParams) override;

  // ----------------------------------------
  // [0] => fromEvent_
  // [1] => toKeys_[0]
  // [2] => toKeys_[1]
  // [3] => ...
  void add(AddDataType datatype, AddValue newval) override;

  // ----------------------------------------
  // utility functions
  void add(KeyCode newval) { add(AddDataType(BRIDGE_DATATYPE_KEYCODE), AddValue(newval.get())); }
  void add(Option newval) { add(AddDataType(BRIDGE_DATATYPE_OPTION), AddValue(newval.get())); }

  bool call_remap_with_VK_PSEUDO_KEY(EventType eventType);

  size_t toKeysSize(void) const { return toKeys_.size(); }
  void clearToKeys(void);

  bool isPressing(void) const { return fromEvent_.isPressing(); }

private:
  static void fire_timer_callback(OSObject* owner, IOTimerEventSource* sender);
  void doTimeout(void);

  int getDelayUntilRepeat(void);
  int getKeyRepeat(void);

  class CurrentToEvent final {
  public:
    enum Value {
      TO_KEYS,
      BEFORE_KEYS,
      AFTER_KEYS,
      TIMEOUT_KEYS,
    };
  };

  Vector_ToEvent& getCurrentToEvent(void) {
    switch (currentToEvent_) {
    case CurrentToEvent::TO_KEYS:
      return toKeys_;
    case CurrentToEvent::BEFORE_KEYS:
      return beforeKeys_;
    case CurrentToEvent::AFTER_KEYS:
      return afterKeys_;
    case CurrentToEvent::TIMEOUT_KEYS:
      return timeoutKeys_;
    }
  }

  size_t index_;

  FromEvent fromEvent_;
  Vector_ModifierFlag fromModifierFlags_;
  Vector_ModifierFlag pureFromModifierFlags_; // fromModifierFlags_ - fromEvent_.getModifierFlag()

  Vector_ToEvent toKeys_;
  Vector_ToEvent beforeKeys_;
  Vector_ToEvent afterKeys_;
  Vector_ToEvent timeoutKeys_;
  CurrentToEvent::Value currentToEvent_;

  static TimerWrapper fire_timer_;
  static KeyToKey* target_;

  int keyboardRepeatID_;
  bool isRepeatEnabled_;

  int delayUntilRepeat_;
  int keyRepeat_;
};
DECLARE_VECTOR(KeyToKey);
}
}

#endif
