Since 10.6.0
------------

* New option has been added into command line interface: `toggle`
* Prepared settings have been updated.
* Updates for people who add new settings by oneself:
    * Option::KEYTOKEY_TIMEOUT has been added.
    * \_\_HoldingKeyToKey\_\_ has been improved at you pressed modifiers while holding target key down.
    * The following filters have been added.
        * &lt;pressingphysicalkeys\_greaterthan&gt;
        * &lt;pressingphysicalkeys\_lessthan&gt;
* Fixed issues:
    * Some Java apps might be crash when AXNotifier is enabled. (Eclipse, Screencast-O-Matic)

Version 10.6.0
--------------

* A following prepared setting has been fixed.
    * General &gt; Disable an internal keyboard while external keyboards are connected.
* "Sort by name" and "Sort by created" button have been added in Preferences &gt; MenuBar.
* Prepared settings have been updated.

Version 10.5.0
--------------

* Fixed issues:
    * Some Java apps might be crash when AXNotifier is enabled. (IntelliJ IDEA, PhpStorm, RubyMine, Android Studio)
    * &lt;device\_only&gt; and &lt;device\_not&gt; filters are ignored when multiple keyboards are connected and same keys are pressed at the same time.
* Improvements:
    * "Ignore bouncing (chattering) events" setting has been added.
    * Spotlight has been supported in &lt;only&gt; and &lt;not&gt; filters.
    * Quit button has been added into Preferences.
    * Simultaneous presses detection with rapid key typing has been improved.
    * ModifierFlag manipulation when key up has been improved.
    * Prepared settings have been updated.
* Updates for people who add new settings by oneself:
    * Option::FORCENUMLOCKON\_FORCE\_OFF has been added.
    * \_\_KeyDownUpToKey\_\_ has been added.
    * &lt;include&gt; ignores missing files. (Karabiner does not show an alert dialog when &lt;include&gt; refers missing files.)

Version 10.4.0
--------------

* A broken prepared setting has been fixed.

Version 10.3.0
--------------

* Stability at reloading XML has been improved.
* OS X 10.10 support has been improved.
* Prepared settings have been updated.
* "Check for updates" (Sparkle) has been updated.
* "Restart AXNotifier" button has been added into Preferences.
* Fixed issue:
    * EventViewer does not show control-tab and control-shift-tab event when Full Keyboard Access is enabled.
* Updates for people who add new settings by oneself:
    * The following filters have been added.
        * &lt;modifierlocked_only&gt;
        * &lt;modifierlocked_not&gt;
        * &lt;modifierstuck_only&gt;
        * &lt;modifierstuck_not&gt;

Version 10.2.0
--------------

* Fixed issues:
    * Shortcuts (eg. Ctrl-C, Ctrl-V) might not work properly in Microsoft Remote Desktop.
    * Some Java apps will be crash.
* Added an option to disable AXNotifier. ("AXNotifier" tab in Preferences.)
* Updated prepared settings.
* Some minor improvements.
* Profile management functions have been added into command line interface.
* Updates for people who add new settings by oneself:
    * \_\_HoldingKeyToKey\_\_ and \_\_KeyOverlaidModifier\_\_ support Option::KEYTOKEY\_BEFORE\_KEYDOWN and Option::KEYTOKEY\_AFTER\_KEYUP.
    * You can also use \_\_{ }\_\_ as well as @begin, @end.

Version 10.1.0
--------------

* Fixed issues:
    * The continuous key sequence will be improper order in environments which VMWare Fusion is installed.
    * A message "Karabiner cannot connect with kernel extension" might be shown in some environment.
* Show an error alert when Karabiner is not placed in /Applications.
* Updates for people who add new settings by oneself:
    * Added KeyCode::VK\_IOHIKEYBOARD\_TOGGLE\_NUMLOCK.
* Updated prepared settings.
* Some minor improvements.

Version 10.0.0
--------------

* KeyRemap4MacBook has been renamed to "Karabiner".
* AXNotifier has been added. <br />
  AXNotifier allows you to observe the window name (window title) and the focused ui element role (eg. whether textarea or not). <br />
  For example, a setting that allows you to use hjkl keys as arrow keys in Finder when you are not editing text such as filename has been added.
* A command line utility "warp-mouse-cursor-position" has been added.<br />
  Settings which use this utility have been added, too.<br />
  For example, this setting allows you to move mouse cursor by tapping fn key:
    * Custom Shortcuts
        * Move mouse cursor to the center of the frontmost app's window:
            * By pressing fn key alone.
* Fixed issues:
    * A message "Kernel extension is not loaded" might be shown in some environment.
    * Status Message will not be shown properly when you are using multiple displays.
* Updated prepared settings.
* Some minor improvements.
* Updates for people who add new settings by oneself:
    * You can add your own modifiers by &lt;modifierdef&gt;.
     [Usage of &lt;modifierdef&gt;.](https://pqrs.org/osx/karabiner/xml.html.en#modifier)
    * Added &lt;windowname\_only&gt; and &lt;windowname\_not&gt; filters.
    * Added &lt;uielementrole\_only&gt; and &lt;uielementrole\_not&gt; filters.
    * Added \_\_PointingRelativeToKey\_\_.
    * Added \_\_PassThrough\_\_. You can disable all settings in specific situations.<br />
      For example, this item allow you to disable all settings while you are using virtual machine.<br />
      (This setting is already included in prepared settings.)
      <pre>
        &lt;item&gt;
          &lt;name&gt;Disable all settings while you are using virtual machine.&lt;/name&gt;
          &lt;identifier&gt;private.ignore_virtual_machine&lt;/identifier&gt;
          &lt;only&gt;VIRTUALMACHINE&lt;/only&gt;
          &lt;autogen&gt;\_\_PassThrough\_\_&lt;/autogen&gt;
        &lt;/item&gt;
      </pre>
    * You can use KeyCode and ConsumerKeyCode in \_\_PointingRelativeToScroll\_\_.
    * Added ThresholdMillisecond into \_\_HoldingKeyToKey\_\_.<br />
      You can control a holding threshold:<br />
      <pre>
        &lt;autogen&gt;
          __HoldingKeyToKey__
          KeyCode::ESCAPE,

          @begin
          KeyCode::ESCAPE
          @end

          @begin
          KeyCode::LAUNCHPAD,
          @end

          &lt;!-- open Launchpad by press and hold the escape key for 2 seconds. --&gt;
          ThresholdMillisecond::RawValue::2000,
        &lt;/autogen&gt;
      </pre>
    * Added \_\_BlockUntilKeyUp\_\_.
    * Added Option::KEYOVERLAIDMODIFIER\_REPEAT\_TOKEYS.
    * Added Option::DROPSCROLLWHEEL\_DROP\_MOMENTUM\_SCROLL.
    * Added KeyCode::VK\_NEGATIVE\_LOCK\_*. (eg. KeyCode::VK\_NEGATIVE\_LOCK\_COMMAND\_L, KeyCode::VK\_NEGATIVE\_LOCK\_SHIFT\_L.)
    * Added KeyCode::VK\_STICKY\_ACTIVE\_MODIFIERS\_*:
        * KeyCode::VK\_STICKY\_ACTIVE\_MODIFIERS\_TOGGLE
        * KeyCode::VK\_STICKY\_ACTIVE\_MODIFIERS\_FORCE\_ON
        * KeyCode::VK\_STICKY\_ACTIVE\_MODIFIERS\_FORCE\_OFF
    * An incompatible change:
        * KeyCode::VK\_JIS\_TEMPORARY_* are removed.<br />
          Please use &lt;inputsource\_filter&gt;, Option::KEYTOKEY\_BEFORE\_KEYDOWN, Option::KEYTOKEY\_AFTER\_KEYUP, KeyCode::JIS\_EISUU and KeyCode::JIS\_KANA instead.

Version 9.3.0
-------------

* Fixed an issue:
    * "Kernel extension is not loaded" alert might be shown on some machines when automatic login is enabled.
* Updated prepared settings.
* Updates for people who add new settings by oneself:
    * These manipulators have been integrated into \_\_KeyToKey\_\_. <br />
      You can change KeyCode, ConsumerKeyCode and PointingButton by \_\_KeyToKey\_\_.
        * \_\_KeyToConsumer\_\_
        * \_\_ConsumerToKey\_\_
        * \_\_ConsumerToConsumer\_\_
        * \_\_KeyToPointingButton\_\_
        * \_\_PointingButtonToKey\_\_
        * \_\_PointingButtonToPointingButton\_\_
    * You can use KeyCode, ConsumerKeyCode and PointingButton in these manipulators:
        * \_\_KeyOverlaidModifier\_\_
        * \_\_HoldingKeyToKey\_\_
        * \_\_SimultaneousKeyPresses\_\_
        * \_\_DoublePressModifier\_\_
        * \_\_ScrollWheelToKey\_\_
        * \_\_PointingRelativeToScroll\_\_
    * Improved KeyCode::VK_CONFIG_* behavior in the edge case.
    * You can change the delay and speed of keyboard repeat per autogen. <br />
      For example, this autogen changes control-p to up arrow with:
        * delay until repeat: 100ms
        * key repeat: 10ms

        <pre>
        &lt;autogen&gt;
          __KeyToKey__
          KeyCode::P, MODIFIERFLAG_EITHER_LEFT_OR_RIGHT_CONTROL,
          KeyCode::CURSOR_UP,
          DelayUntilRepeat::RawValue::100,
          KeyRepeat::RawValue::10,
        &lt;/autogen&gt;
        </pre>

Version 9.2.0
-------------

* KeyRemap4MacBook no longer requires system restart at installing or upgrading. <br />
  If you need to restart system for some reason, KeyRemap4MacBook will show an alert which urges you to restart.
* Fixed issues:
    * System might crash when you disconnected a keyboard.

Version 9.0.0
-------------

* Optimized for OS X 10.9. <br />
  KeyRemap4MacBook 9.0.0 requires OS X 10.9+.
* Added delay configurations into multi-touch extension.
* Drop power button support due to limitations of OS X 10.9. <br />
  You can no longer change the power button on MacBook.
* Fixed issues:
    * ENV\_HOME does not work properly in included xml.
    * New plugged devices will not be recognized on OS X 10.9.
    * KeyRemap4MacBook disables the shut down dialog.
    * Fn key on Leopold FC660M cancels mouse dragging.
* Updated prepared settings:
    * "VIM Emulation" has been updated.
    * Fixed "MarkSet" in Emacs Mode.
* Updated installer.
* Some minor improvements.
* Signed with Developer ID.


Version 8.4.0
-------------

* Icons have been refined. (Thanks to Kouji TAMURA.)
* Introduced @begin and @end in private.xml. <br />
  You can use more than one key at \_\_KeyOverlaidModifier\_\_, \_\_DoublePressModifier\_\_.
* Supported shell commands execution with KeyCode::VK\_OPEN\_URL\_*.


Version 8.3.0
-------------

* Fixed a bug that "Look up" feature of OS X (tap trackpad with three fingers) does not work properly.
* Some minor improvements.


Version 8.2.0
-------------

* Fixed a bug that object selection is disabled on Adobe Fireworks.
* Fixed a bug that "General > Don't remap XXX" does not take effect immediately.
* Fixed a bug that control-eject shortcut does not work properly on OS X 10.7 and 10.6.


Version 8.1.0
-------------

* Power button remapping has been supported. (Thanks to Peter Kamb who is the author of PowerKey.)
* Added "Quit KeyRemap4MacBook" into menu bar.
* Added some styles into status message indicator.
* Improved compatibility with SmoothMouse.
* Supported more than three keys at \_\_SimultaneousKeyPresses\_\_.
* Added KeyCode::VK\_OPEN\_URL\_*.
* Added KeyCode::VK\_PARTIAL\_KEYDOWN and KeyCode::VK\_PARTIAL\_KEYUP.
* Added Option::POINTINGRELATIVETOSCROLL\_TOKEYS.
* Added \_\_FlipPointingRelative\_\_.
* Added \_\_FlipScrollWheel\_\_.
* Added filters:
    * &lt;lastpressedphysicalkey\_not&gt;
    * &lt;lastpressedphysicalkey\_only&gt;
    * &lt;elapsedtimesincelastpressed\_greaterthan&gt;
    * &lt;elapsedtimesincelastpressed\_lessthan&gt;
* Some minor improvements.


Version 8.0.0
-------------

* Changed Preferences location. <br />
  https://pqrs.org/osx/karabiner/document.html
* Changed KeyRemap4MacBook\_cli location. <br />
  https://pqrs.org/osx/karabiner/document.html#commandlineinterface
* Integrated a status message indicator. (Removed Growl support.)
* Dynamic VK\_CHANGE\_INPUTSOURCE definition feature has been added.
* Dynamic &lt;inputsource\_only&gt; definition feature has been added.
* Changed --KeyToKey-- to \_\_KeyToKey\_\_ at &lt;autogen&gt;.
* Added a preference of ignored area into "multi-touch extension".
* Added Option::SIMULTANEOUSKEYPRESSES\_STRICT\_KEY\_ORDER.
* Added DeviceLocation into &lt;device\_only&gt;, &lt;device\_not&gt; filters.
* Some minor improvements.


Version 7.8.0
-------------

* Fixed a bug that private.xml does not work properly if &lt;identifier&gt; contains white space.
* Fixed a bug that "General &gt; Don't restore modifiers in the mouse event" does not work properly.
* Some minor improvements.


Version 7.7.0
-------------

* Fixed a bug introduced in version 7.6.0 that detecting of Input Sources does not work properly in Japanese and some other languages.


Version 7.6.0
-------------

* Added &lt;replacementdef&gt;. You can replace preset settings behavior by this.
* Added &lt;include&gt;. You can load xml files in private.xml.
* Added --ScrollWheelToKey--.
* Added --ScrollWheelToScrollWheel--.
* Added KeyCode::VK\_WAIT\_*.
* Improved KeyCode::VK\_CHANGE\_INPUTMODE\_* behavior.
* Improved XML processing engine. (XML reloading is 2x faster.)
* Some minor improvements.


Version 7.5.0
-------------

* Dynamic ApplicationType,DeviceVendor,DeviceProduct definition feature has been added.
* Support Growl-1.3 on notifications. <br />
  https://pqrs.org/osx/karabiner/document.html
* Added --StripModifierFromScrollWheel--.
* Added Option::KEYTOKEY\_BEFORE\_KEYDOWN, Option::KEYTOKEY\_AFTER\_KEYUP.
* Added KeyCode::VK\_CONSUMERKEY\_*.
* Some minor improvements.
* Added about 40 kinds settings to preset.


Version 7.4.0
-------------

* Some improvements on Mac OS X 10.7 (Lion).
* Removed "General &gt; Enable CapsLock LED Hack".<br />
  If you're using this setting for PCKeyboardHack, use "No Action" configuration instead. <br />
  https://pqrs.org/osx/karabiner/seil.html#usage
* Clean up "Simultaneous Vi Mode". <br />
  (and split some options into "Home Row Arrow and Modifier Mode".)
* Added "[Key Overlaid Modifier] Initial Modifier Wait" preference into "Key Repeat" tab. <br />
  KeyOverlaidModifier changes key to modifier after this wait. <br />
  This preference is useful if your typing speed is too fast.
* Added KeyCode::VK\_STICKY\_*\_FORCE\_ON, KeyCode::VK\_STICKY\_*\_FORCE\_OFF.
* Added --DropScrollWheel--.
* Some minor improvements.
* Added some settings to preset.


Version 7.3.0
-------------

* Improved stability when using Sticky Keys in Universal Access.
* Improved stability when using multi-touch extension together.
* Improved "Lazy-Modifier (KeyCode::VK\_LAZY\_*)" behavior.
* Some minor improvements.
* Clean up the internal source code. The connection between kernel and userspace became more easier to understand.
* Added KeyCode::VK\_MOUSEKEY\_BUTTON\_*.
* Added Option::NOREPEAT at &lt;autogen&gt;.
* Added DeviceProduct::ANY at &lt;device\_only&gt;, &lt;device\_not&gt;.
* Added about 80 kinds settings.


version 7.2.0
-------------

* Fixed a bug that Growl notification did not work in specific environment.
* Fixed a bug that the default setting of checkForUpdate was "Nothing".
* Improved multi-touch extension around sleep/wakeup.
* Added about 20 kinds settings.

Version 7.1.0
-------------

* Added setting to be able to use "Logitech Number Pad" which we were not able not use in Mac OS X. <br />
  Activate "Change KeyPad Key &gt; Logitech Number Pad Hack".
* Replaced StatusWindow with Growl. <br />
  StatusWindow was displaying the lock state of modifiers and extra message. <br />
  Now, these messages are shown by Growl. <br />
  https://pqrs.org/osx/karabiner/img/growl.png <br />
  http://growl.info/
* Attached an application named "multi-touch extension". <br />
  This application activates specific setting while fingers touch the multi-touch device. <br />
  ThumbSense is one of the function which this application supplies. <br />
* Improve UI of checkForUpdate.
* Fixed some bugs.
* Added about 140 kinds settings.
* Added &lt;modifier\_only&gt;, &lt;modifier\_not&gt; filters.
* Added --ForceNumLockOn-- to &lt;autogen&gt;.
