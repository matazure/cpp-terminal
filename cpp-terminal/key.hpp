#pragma once

#include <cstdint>

namespace Term
{

class Key
{
public:
  enum Value : std::int32_t
  {
    NO_KEY             = -1,
    // Begin ASCII (some ASCII names has been change to their CTRL + key part)
    NUL                = 0,
    CTRL_A             = 1,
    CTRL_B             = 2,
    CTRL_C             = 3,
    CTRL_D             = 4,
    CTRL_E             = 5,
    CTRL_F             = 6,
    CTRL_G             = 7,
    BACKSPACE          = 8,
    TAB                = 9,
    CTRL_J             = 10,
    CTRL_K             = 11,
    CTRL_L             = 12,
    ENTER              = 13,  // Mapped to ENTER
    CTRL_N             = 14,
    CTRL_O             = 15,
    CTRL_P             = 16,
    CTRL_Q             = 17,
    CTRL_R             = 18,
    CTRL_S             = 19,
    CTRL_T             = 20,
    CTRL_U             = 21,
    CTRL_V             = 22,
    CTRL_W             = 23,
    CTRL_X             = 24,
    CTRL_Y             = 25,
    CTRL_Z             = 26,
    ESC                = 27,
    CTRL_SLASH         = 28,
    CTRL_CLOSE_BRACKET = 29,
    CTRL_CARET         = 30,
    CTRL_UNDERSCORE    = 31,
    SPACE              = 32,
    EXCLAMATION_MARK   = 33,
    QUOTE              = 34,
    HASH               = 35,
    DOLLAR             = 36,
    PERCENT            = 37,
    AMPERSAND          = 38,
    APOSTROPHE         = 39,
    OPEN_PARENTHESIS   = 40,
    CLOSE_PARENTHESIS  = 41,
    ASTERISK           = 42,
    PLUS               = 43,
    COMMA              = 44,
    HYPHEN             = 45,
    MINUS              = 45,
    PERIOD             = 46,
    SLASH              = 47,
    ZERO               = 48,
    ONE                = 49,
    TWO                = 50,
    THREE              = 51,
    FOUR               = 52,
    FIVE               = 53,
    SIX                = 54,
    SEVEN              = 55,
    EIGHT              = 56,
    NINE               = 57,
    COLON              = 58,
    SEMICOLON          = 59,
    LESS_THAN          = 60,
    OPEN_CHEVRON       = 60,
    EQUAL              = 61,
    GREATER_THAN       = 62,
    CLOSE_CHEVRON      = 62,
    QUESTION_MARK      = 63,
    AROBASE            = 64,
    A                  = 65,
    B                  = 66,
    C                  = 67,
    D                  = 68,
    E                  = 69,
    F                  = 70,
    G                  = 71,
    H                  = 72,
    I                  = 73,
    J                  = 74,
    K                  = 75,
    L                  = 76,
    M                  = 77,
    N                  = 78,
    O                  = 79,
    P                  = 80,
    Q                  = 81,
    R                  = 82,
    S                  = 83,
    T                  = 84,
    U                  = 85,
    V                  = 86,
    W                  = 87,
    X                  = 88,
    Y                  = 89,
    Z                  = 90,
    OPEN_BRACKET       = 91,
    BACKSLASH          = 92,
    CLOSE_BRACKET      = 93,
    CARET              = 94,
    UNDERSCORE         = 95,
    GRAVE_ACCENT       = 96,
    a                  = 97,
    b                  = 98,
    c                  = 99,
    d                  = 100,
    e                  = 101,
    f                  = 102,
    g                  = 103,
    h                  = 104,
    i                  = 105,
    j                  = 106,
    k                  = 107,
    l                  = 108,
    m                  = 109,
    n                  = 110,
    o                  = 111,
    p                  = 112,
    q                  = 113,
    r                  = 114,
    s                  = 115,
    t                  = 116,
    u                  = 117,
    v                  = 118,
    w                  = 119,
    x                  = 120,
    y                  = 121,
    z                  = 122,
    OPEN_BRACE         = 123,
    VERTICAL_BAR       = 124,
    CLOSE_BRACE        = 125,
    TILDE              = 126,
    DEL                = 127,
    // End ASCII
    // Extended ANSII goes up to 255
    ARROW_LEFT         = 256,
    ARROW_RIGHT,
    ARROW_UP,
    ARROW_DOWN,
    CTRL_UP,
    CTRL_DOWN,
    CTRL_RIGHT,
    CTRL_LEFT,
    NUMERIC_5,
    HOME,
    INSERT,
    END,
    PAGE_UP,
    PAGE_DOWN,
    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7,
    F8,
    F9,
    F10,
    F11,
    F12,
    F13,
    F14,
    F15,
    F16,
    F17,
    F18,
    F19,
    F20,
    F21,
    F22,
    F23,
    F24,
    PRINT_SCREEN,
    // Keys below need to be under 512
    // special keys (CTRL is special^2)
    CTRL = -AROBASE,
    // Now use << to for detecting special key + key press
    ALT  = (1 << 9)
  };
  Key() = default;
  Key(const Term::Key::Value& value);
  // clang-format off
  operator Term::Key::Value();
  // clang-format on
  // Detect if Key is convertible to ANSII
  bool is_ASCII();
  // Detect if Key is convertible to Extended ANSII
  bool is_extended_ASCII();
  // Detect if Key is CTRL+*
  bool is_CTRL();
  // Detect if Key is ALT+*
  bool is_ALT();
  bool empty();

private:
  Value m_value{NO_KEY};
};

}  // namespace Term
