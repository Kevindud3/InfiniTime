/*  Copyright (C) 2020 JF, Adam Pigg, Avamander

    This file is part of InfiniTime.

    InfiniTime is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    InfiniTime is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#pragma once

#include <FreeRTOS.h>
#include <lvgl/src/lv_core/lv_obj.h>
#include <string>
#include "displayapp/screens/Screen.h"
#include "displayapp/apps/Apps.h"
#include "displayapp/Controllers.h"
#include "Symbols.h"
#include "components/motor/MotorController.h" // Include MotorController
#include "components/datetime/DateTimeController.h" // Include DateTimeController


namespace Pinetime {
  namespace Controllers {
    class MusicService;
  }

  namespace Applications {
    namespace Screens {
      class Music : public Screen {
      public:
        Music(Pinetime::Controllers::MusicService& music, Pinetime::Controllers::MotorController& motorController, Controllers::DateTime& dateTimeController); // Add DateTimeController to constructor

        ~Music() override;

        void Refresh() override;

        void OnObjectEvent(lv_obj_t* obj, lv_event_t event);
        bool OnButtonPushed() override;

      private:
        bool OnTouchEvent(TouchEvents event) override;

        void UpdateLength();

        lv_obj_t* btnPrev;
        lv_obj_t* btnPlayPause;
        lv_obj_t* btnNext;
        lv_obj_t* btnVolDown;
        lv_obj_t* btnVolUp;
        lv_obj_t* txtArtist;
        lv_obj_t* txtTrack;
        lv_obj_t* txtPlayPause;

        lv_obj_t* imgDisc;
        lv_obj_t* imgDiscAnim;
        lv_obj_t* txtTrackDuration;

        lv_style_t btn_style;

        /** For the spinning disc animation */
        bool frameB;

        Pinetime::Controllers::MusicService& musicService;
        Pinetime::Controllers::MotorController& motorController; // Add MotorController as a member
        Controllers::DateTime& dateTimeController; // Add DateTimeController as a member

        std::string artist;
        std::string album;
        std::string track;

        /** Total length in seconds */
        int totalLength = 0;
        /** Current position in seconds */
        int currentPosition;
        /** Last time an animation update or timer was incremented */
        TickType_t lastIncrement = 0;

        bool playing;

        lv_task_t* taskRefresh;
        lv_task_t* taskUpdate;
        lv_obj_t* label_time;

        /** Watchapp */
        static void lv_update_task(struct _lv_task_t* task);
        void UpdateScreen();
      };
    }

    template <>
    struct AppTraits<Apps::Music> {
      static constexpr Apps app = Apps::Music;
      static constexpr const char* icon = Screens::Symbols::music;

      static Screens::Screen* Create(AppControllers& controllers) {
        return new Screens::Music(*controllers.musicService, controllers.motorController, controllers.dateTimeController); // Pass DateTimeController to the Music constructor
      };

      static bool IsAvailable(Pinetime::Controllers::FS& /*filesystem*/) {
        return true;
      };
    };
  }
}
