/* Copyright (c) 2021 Xie Meiyi(xiemeiyi@hust.edu.cn) and OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2022/5/22.
//

#pragma once

#include "rc.h"
#include "sql/parser/parse_defs.h"
#include "sql/stmt/stmt.h"
#include <cstddef>

class Table;
class Db;
using TArray=const Value (*)[MAX_NUM];
class InsertStmt : public Stmt
{
public:

  InsertStmt() = default;
  InsertStmt(Table *table, TArray values, const size_t* value_amount,size_t row);

  StmtType type() const override {
    return StmtType::INSERT;
  }
public:
  static RC create(Db *db, const Inserts &insert_sql, Stmt *&stmt);

public:
  Table *table() const {return table_;}
  TArray values() const { return values_; }
  const size_t* value_amount() const { return value_amount_; }
  size_t return_row() const{return value_row;}

private:
  Table *table_ = nullptr;
  TArray values_= nullptr;
  const size_t *value_amount_=nullptr;
  size_t value_row = 0;
};

