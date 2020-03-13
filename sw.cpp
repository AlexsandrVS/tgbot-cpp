void build(Solution &s)
{
    auto &tgbot = s.addTarget<StaticLibraryTarget>("reo7sp.tgbot", "1.2.0");
    tgbot += Git("https://github.com/reo7sp/tgbot-cpp", "v{M}.{m}");

    tgbot.Public += "org.sw.demo.boost.property_tree"_dep;
    tgbot.Public += "org.sw.demo.openssl.ssl"_dep;
    tgbot.Public += "org.sw.demo.boost.system"_dep;
    tgbot.Public += "org.sw.demo.boost.date_time"_dep;
    tgbot.Public += "org.sw.demo.badger.curl.libcurl"_dep, "HAVE_CURL"_def;
    tgbot.Public += "org.sw.demo.boost.asio"_dep;
}