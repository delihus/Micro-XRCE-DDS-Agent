// Copyright 2017 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

/*! 
 * @file ShapePubSubTypes.cpp
 * This header file contains the implementation of the serialization functions.
 *
 * This file was generated by the tool fastcdrgen.
 */


#include <fastcdr/FastBuffer.h>
#include <fastcdr/Cdr.h>

#include <agent/types/ShapePubSubTypes.h>

ShapeTypePubSubType::ShapeTypePubSubType() {
    setName("ShapeType");
    m_typeSize = (uint32_t)ShapeType::getMaxCdrSerializedSize() + 4 /*encapsulation*/;
    m_isGetKeyDefined = ShapeType::isKeyDefined();
    m_keyBuffer = (unsigned char*)malloc(ShapeType::getKeyMaxCdrSerializedSize()>16 ? ShapeType::getKeyMaxCdrSerializedSize() : 16);
}

ShapeTypePubSubType::~ShapeTypePubSubType() {
    if(m_keyBuffer!=nullptr)
        free(m_keyBuffer);
}

bool ShapeTypePubSubType::serialize(void *data, SerializedPayload_t *payload)
{
    std::vector<unsigned char>* buffer = reinterpret_cast<std::vector<unsigned char>*>(data);
    payload->data[0] = 0;
    payload->data[1] = 1;
    payload->data[2] = 0;
    payload->data[3] = 0;
    memcpy(&payload->data[4], buffer->data(), buffer->size());
    payload->length = (uint32_t)buffer->size() + 4; //Get the serialized length
    return true;
}

bool ShapeTypePubSubType::deserialize(SerializedPayload_t* payload, void* data)
{
    std::vector<unsigned char>* buffer = reinterpret_cast<std::vector<unsigned char>*>(data);
    buffer->assign(payload->data + 4, payload->data + payload->length);

    return true;
}

std::function<uint32_t()> ShapeTypePubSubType::getSerializedSizeProvider(void* data) {
    return [data]() -> uint32_t
    {
        return (uint32_t)type::getCdrSerializedSize(*static_cast<ShapeType*>(data)) + 4 /*encapsulation*/;
    };
}

void* ShapeTypePubSubType::createData() {
    return (void*)new ShapeType();
}

void ShapeTypePubSubType::deleteData(void* data) {
    delete((ShapeType*)data);
}

bool ShapeTypePubSubType::getKey(void *data, InstanceHandle_t* handle)
{
    if(!m_isGetKeyDefined)
        return false;
    ShapeType* p_type = (ShapeType*) data;
    //ShapeType* p_type = &(((ShapeTypePlus*)data)->shape);
    eprosima::fastcdr::FastBuffer fastbuffer((char*)m_keyBuffer,ShapeType::getKeyMaxCdrSerializedSize()); 	// Object that manages the raw buffer.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS); 	// Object that serializes the data.
    p_type->serializeKey(ser);
    if(ShapeType::getKeyMaxCdrSerializedSize()>16)	{
        m_md5.init();
        m_md5.update(m_keyBuffer,(unsigned int)ser.getSerializedDataLength());
        m_md5.finalize();
        for(uint8_t i = 0;i<16;++i)    	{
            handle->value[i] = m_md5.digest[i];
        }
    }
    else    {
        for(uint8_t i = 0;i<16;++i)    	{
            handle->value[i] = m_keyBuffer[i];
        }
    }
    return true;
}

