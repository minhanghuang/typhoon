/*
* Copyright (C) Trunk Technology, Inc. - All Rights Reserved
*
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*
* Written by Huang Minhang <huangminhang@trunk.tech>, 2021/5/23 17:43
*/
#ifndef TYPHOON_APP_H
#define TYPHOON_APP_H
#include <memory>
#include <unordered_map>
#include <typhoon/web.h>
#include "view.h"

namespace typhoon {
namespace app {

    class Application : public web::Application {
    public:
        ~Application();
        Application();

    private:
        void on_http(const web::ConHdl&) final; // http 钩子
        int reverse_url(const std::string&);

    private:
        std::shared_ptr<View> m_view_ptr;
        enum url {ok=0};
        std::unordered_map<std::string, unsigned int> router =  {
            std::pair<std::string, unsigned int>("/api/ok/",url::ok),
        };

    };

} // namespace app
} // namespace typhoon

#endif //TYPHOON_APP_H
