// Copyright 2018 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _MICRORTPS_AGENT_TOPIC_TOPIC_HPP_
#define _MICRORTPS_AGENT_TOPIC_TOPIC_HPP_

#include <micrortps/agent/object/XRCEObject.hpp>
#include <micrortps/agent/types/TopicPubSubType.hpp>
#include <string>
#include <memory>
#include <set>

namespace eprosima {
namespace micrortps {

class Participant;

class Topic : public XRCEObject
{
  public:
    Topic(const dds::xrce::ObjectId& object_id, const std::shared_ptr<Participant>& participant);
    Topic(Topic&&)      = default;
    Topic(const Topic&) = default;
    Topic& operator=(Topic&&) = default;
    Topic& operator=(const Topic&) = default;
    ~Topic() override;

    bool init(const std::string& xmlrep);
    virtual void release(ObjectContainer&) override;
    void tie_object(const dds::xrce::ObjectId& object_id) { tied_objects_.insert(object_id); }
    void untie_object(const dds::xrce::ObjectId& object_id) { tied_objects_.erase(object_id); }

  private:
    std::string name;
    std::string type_name;
    std::shared_ptr<Participant> participant_;
    TopicPubSubType generic_type_;
    std::set<dds::xrce::ObjectId> tied_objects_;
};

} // namespace micrortps
} // namespace eprosima

#endif //_MICRORTPS_AGENT_TOPIC_TOPIC_HPP_
