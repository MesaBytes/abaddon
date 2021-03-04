#pragma once
#include <string>
#include <type_traits>
#include <SimpleIni.h>

class SettingsManager {
public:
    SettingsManager(std::string filename);
    void Reload();

    void Close();
    bool GetUseMemoryDB() const;
    std::string GetUserAgent() const;
    std::string GetDiscordToken() const;
    bool GetShowMemberListDiscriminators() const;
    bool GetShowEmojis() const;
    std::string GetLinkColor() const;
    int GetCacheHTTPConcurrency() const;
    bool GetPrefetch() const;
    std::string GetMainCSS() const;
    bool GetShowAnimations() const;
    bool GetShowOwnerCrown() const;

    bool IsValid() const;

    template<typename T>
    void SetSetting(std::string section, std::string key, T value) {
        m_ini.SetValue(section.c_str(), key.c_str(), std::to_string(value).c_str());
        m_ini.SaveFile(m_filename.c_str());
    }

    void SetSetting(std::string section, std::string key, std::string value) {
        m_ini.SetValue(section.c_str(), key.c_str(), value.c_str());
        m_ini.SaveFile(m_filename.c_str());
    }

private:
    std::string GetSettingString(const std::string &section, const std::string &key, std::string fallback = "") const;
    int GetSettingInt(const std::string &section, const std::string &key, int fallback) const;
    bool GetSettingBool(const std::string &section, const std::string &key, bool fallback) const;

private:
    bool m_ok;
    std::string m_filename;
    CSimpleIniA m_ini;
};
