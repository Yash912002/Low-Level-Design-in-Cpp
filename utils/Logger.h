#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <sstream>
#include <string>

#if defined(_WIN32)
#include <windows.h>
inline void enableANSIColors() {
  static bool enabled = false;
  if (!enabled) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE) {
      DWORD dwMode = 0;
      if (GetConsoleMode(hOut, &dwMode)) {
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, dwMode);
      }
    }
    enabled = true;
  }
}
#else
inline void enableANSIColors() {}
#endif

namespace Color {
constexpr const char *Reset = "\033[0m";
constexpr const char *Red = "\033[1;31m";
constexpr const char *Green = "\033[1;32m";
constexpr const char *Yellow = "\033[1;33m";
constexpr const char *Blue = "\033[1;34m";
constexpr const char *Cyan = "\033[1;36m";
} // namespace Color

class Logger {
private:
  template <typename T> static std::string toString(const T &value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
  }

  template <typename... Args> static std::string join(const Args &...args) {
    std::ostringstream oss;
    (oss << ... << args); // fold expression (C++17)
    return oss.str();
  }

public:
  template <typename... Args> static void info(const Args &...args) {
    enableANSIColors();
    std::cout << Color::Cyan << "[INFO] " << join(args...) << Color::Reset
              << '\n';
  }

  template <typename... Args> static void success(const Args &...args) {
    enableANSIColors();
    std::cout << Color::Green << "[SUCCESS] " << join(args...) << Color::Reset
              << '\n';
  }

  template <typename... Args> static void warn(const Args &...args) {
    enableANSIColors();
    std::cout << Color::Yellow << "[WARNING] " << join(args...) << Color::Reset
              << '\n';
  }

  template <typename... Args> static void error(const Args &...args) {
    enableANSIColors();
    std::cerr << Color::Red << "[ERROR] " << join(args...) << Color::Reset
              << '\n';
  }
};

// -------- Macros for shorter calls --------
#define LOG_INFO(...) Logger::info(__VA_ARGS__)
#define LOG_SUCCESS(...) Logger::success(__VA_ARGS__)
#define LOG_WARN(...) Logger::warn(__VA_ARGS__)
#define LOG_ERROR(...) Logger::error(__VA_ARGS__)

#endif
