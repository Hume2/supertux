//  SuperTux
//  Copyright (C) 2006 Matthias Braun <matze@braunis.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_SUPERTUX_TRIGGER_SECRETAREA_TRIGGER_HPP
#define HEADER_SUPERTUX_TRIGGER_SECRETAREA_TRIGGER_HPP

#include "trigger/trigger_base.hpp"

#include "object/tilemap.hpp"
#include "supertux/timer.hpp"
#include "util/reader_fwd.hpp"
#include "util/writer_fwd.hpp"

class DrawingContext;
class Color;

class SecretAreaTrigger : public TriggerBase
{
  static Color text_color;
public:
  SecretAreaTrigger(const Reader& reader);
  SecretAreaTrigger(const Rectf& area, std::string fade_tilemap = "");
  ~SecretAreaTrigger();
  virtual void save(lisp::Writer& writer);
  virtual std::string get_class() {
    return "secretarea";
  }

  void event(Player& player, EventType type);
  void draw(DrawingContext& context);
  std::string get_fade_tilemap_name();

private:
  Timer message_timer;
  bool message_displayed;
  std::string message; /**< message to display, default "You found a secret area!" */
  std::string fade_tilemap; /**< tilemap to fade away when trigger is activated, or empty if you don't care */
  std::string script; /**< optional script to run when trigger is activated */
};

#endif

/* EOF */
