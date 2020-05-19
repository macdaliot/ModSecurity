/*
 * ModSecurity, http://www.modsecurity.org/
 * Copyright (c) 2015 - 2020 Trustwave Holdings, Inc. (http://www.trustwave.com/)
 *
 * You may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * If any of the files related to licensing are missing or if you have any
 * other questions related to licensing please contact Trustwave Holdings, Inc.
 * directly using the email address security@modsecurity.org.
 *
 */

#include <string>

#include "src/actions/action_type_configure.h"


#ifndef SRC_ACTIONS_REV_H_
#define SRC_ACTIONS_REV_H_

class Transaction;

namespace modsecurity {
class Transaction;
namespace actions {


class Rev : public ActionTypeConfigure {
 public:
    explicit Rev(const std::string &action)
        : ActionTypeConfigure(action),
        m_revision("")
    { };

    bool init(std::string *error) override;
    virtual void configure(RuleWithActions *rule) override {
        rule->setRevision(m_revision);
    }
 private:
   std::string m_revision;
};


}  // namespace actions
}  // namespace modsecurity

#endif  // SRC_ACTIONS_REV_H_
