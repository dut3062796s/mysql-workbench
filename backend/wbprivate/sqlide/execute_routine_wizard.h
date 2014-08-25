/* 
 * Copyright (c) 2014, Oracle and/or its affiliates. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of the
 * License.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301  USA
 */

#pragma  once

#include "mforms/form.h"

#ifdef __linux__
#include "grts/structs.db.mysql.h"
#endif

namespace mforms {
  class Button;
  class TextEntry;
}

class ExecuteRoutineWizard : public mforms::Form
{
private:
  db_mysql_RoutineRef _routine;
  db_mysql_CatalogRef _catalog;
  std::vector<mforms::TextEntry *> _edits;
  std::string _sql_mode;

  mforms::Button *_cancel_button;
  mforms::Button *_execxute_button;

  bool needs_quoting(const std::string &type);
public:
  ExecuteRoutineWizard(db_mysql_RoutineRef routine, const std::string &sql_mode);

  std::string run();
};