#include "f1c/bootstrap/application.hpp"

#include <windows.h>
#include <shellapi.h>

#include <filesystem>
#include <stdexcept>
#include <string>
#include <vector>

namespace {

std::filesystem::path executable_path() {
    std::wstring buffer(32768, L'\0');
    const auto length = GetModuleFileNameW(nullptr, buffer.data(),
                                           static_cast<DWORD>(buffer.size()));
    if (length == 0 || length == buffer.size()) {
        throw std::runtime_error("GetModuleFileNameW failed");
    }
    buffer.resize(length);
    return buffer;
}

std::vector<std::wstring> command_line_arguments() {
    int count = 0;
    auto* values = CommandLineToArgvW(GetCommandLineW(), &count);
    if (!values) {
        throw std::runtime_error("CommandLineToArgvW failed");
    }
    std::vector<std::wstring> result(values, values + count);
    LocalFree(values);
    return result;
}

}  // namespace

int WINAPI wWinMain(HINSTANCE, HINSTANCE, PWSTR, int) {
    try {
        const auto options = f1c::bootstrap::parse_options(
            command_line_arguments(), executable_path());
        return f1c::bootstrap::Application{}.run(options);
    } catch (const std::exception& error) {
        MessageBoxA(nullptr, error.what(), "F1 Challenge Replacement Engine",
                    MB_OK | MB_ICONERROR);
        return 1;
    }
}
