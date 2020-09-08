#pragma once
#include "Core/CoreFramework.h"
#include "Core/Threading/Thread.h"
#include "Core/Events/Event.h"
#include "Core/Events/EventArgs/CancelEventArgs.h"
#include "WindowEventArgs.h"
#include "Core/System/Debug/Log.h"
#include "Core/Exceptions/Exceptions.h"
#include "Core/System/Property.h"

using namespace Pictura::Debug;

namespace Pictura::UI
{
    enum class WindowState
    {
        Normal = 0,
        Minimized = 1,
        Maximized = 2,
        Fullscreen = 3
    };

    enum class MessageBoxIcon
    {
        NoIcon = 0x00000000L,
        Error = 0x00000010L,
        Question = 0x00000020L,
        Warning = 0x00000030L,
        Info = 0x00000040L,
    };

    enum class MessageBoxButtons
    {
        OkOnly = 0x00000000L,
        OkCancel = 0x00000001L,
        AbortRetryIgnore = 0x00000002L,
        YesNoCancel = 0x00000003L,
        YesNo = 0x00000004L,
        RetryCancel = 0x00000005L,
        CancelTryContinue = 0x00000006L,
    };

    enum class MessageBoxResult
    {
        Ok = 1,
        Cancel = 2,
        Abort = 3,
        Retry = 4,
        Ignore = 5,
        Yes = 6,
        No = 7,
        TryAgain = 10,
        Continue = 11,
    };

    class NullWindow
    {
      public:
        virtual ~NullWindow() {}

      public:
        virtual void Show() = 0;
        virtual void Hide() = 0;

        virtual void Close() = 0;

        virtual void Focus() = 0;
        virtual void Update() = 0;

        virtual MessageBoxResult ShowMessageBox(WideString Message, WideString Title, MessageBoxIcon Icons, MessageBoxButtons Buttons) = 0;

      protected:
        virtual void SetFullscreen(bool value) = 0;

      protected:
        virtual void OnTitleChanged(const String &newValue) = 0;
        virtual void OnPositionChanged(const Maths::Vector2 &newValue) = 0;
        virtual void OnSizeChanged(const Maths::Vector2 &newValue) = 0;
        virtual void OnStateChanged(const WindowState &newValue) = 0;

      public:
        void *OwnerPtr = nullptr;
        NativeHandleType &GetHandle() { return m_Handle; }
        static inline Map<NativeHandleType, UI::NullWindow *> WindowList = {};

      protected:
        NativeHandleType m_Handle = nullptr;
        bool isActive = false;

      public:
        event(PositionEventArgs, PositionChanging);
        event(SizeEventArgs, Resized);
        event(CancelEventArgs, Closing);
        event(EventArgs, StateChanged);
        event(EventArgs, Shown);

      public:
        Property<bool> Topmost = false;
        Property<bool> Resizable = true;
        Property<bool> Decorated = true;
        Property<WindowState> WindowState = {WindowState::Normal, this, &NullWindow::OnStateChanged};

        Property<String> Title = {"Untitled Window", this, &NullWindow::OnTitleChanged};

        Property<Maths::Vector2> Position = {Maths::Vector2(), this, &NullWindow::OnPositionChanged};
        Property<Maths::Vector2> Size = {Maths::Vector2(850, 450), this, &NullWindow::OnSizeChanged};

        Property<Maths::Vector2> MinSize = Maths::Vector2(425, 225);
        Property<Maths::Vector2> MaxSize = Maths::Vector2();
    };
}