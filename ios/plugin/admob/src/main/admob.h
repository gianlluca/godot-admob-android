//
//  admob.h
//  admob
//
//  Created by Gustavo Maciel on 16/01/21.
//

#ifndef admob_plugin_implementation_h
    #define admob_plugin_implementation_h
    #include "core/object.h"

    #ifdef __OBJC__
        #include "../formats/Banner.h"
        #include "../formats/Interstitial.h"
        #include "../formats/Rewarded.h"

        @class Banner;
        @class Interstitial;
        @class Rewarded;
        
        typedef Banner *banner;
        typedef Interstitial *interstitial;
        typedef Rewarded *rewarded;
    #else
        typedef void *banner;
        typedef void *interstitial;
        typedef void *rewarded;
    #endif

    class AdMob : public Object {
        GDCLASS(AdMob, Object);
        
        bool initialized;
        bool is_for_child_directed_treatment;
        bool is_test_europe_user_consent;
        String self_max_ad_content_rating;
        static AdMob *instance;
        Object *objectDB;

        banner bannerObj;
        interstitial interstitialObj;
        rewarded rewardedObj;

    protected:
        static void _bind_methods();
        
    public:
        void initialize(bool is_for_child_directed_treatment,
                        const String &max_ad_content_rating,
                        bool is_real,
                        bool is_test_europe_user_consent,
                        int instance_id);
        
        void load_banner(const String &ad_unit_id,
                         int gravity,
                         const String &size);
        
        void destroy_banner();
        
        float get_banner_width();
        float get_banner_height();
        float get_banner_width_in_pixels();
        float get_banner_height_in_pixels();

        void load_interstitial(const String &ad_unit_id);
        void show_interstitial();
        void load_rewarded(const String &ad_unit_id);
        void show_rewarded();
        
        void request_user_consent();
        void reset_consent_state();

        AdMob();
        ~AdMob();
    private:
        const char* getDeviceId();
        void GADInitialize();
       
        void loadConsentForm(bool is_for_child_directed_treatment,
                             bool is_real,
                             int instance_id);

    };


#endif /* admob_plugin_implementation_h */
