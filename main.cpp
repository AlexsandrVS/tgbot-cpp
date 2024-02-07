#include <iostream>
#include <tgbot/tgbot.h>

int main() {
    TgBot::Bot bot("6601404963:AAG65Uqfvf7jp_IeJpQFZz9Xd-L6I_jT9xo");
    
    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Привет, я твой новый телеграм-бот!");
    });

    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Получено сообщение: " + message->text);
    });

    bot.getApi().deleteWebhook();

    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());

        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }

    return 0;
}
