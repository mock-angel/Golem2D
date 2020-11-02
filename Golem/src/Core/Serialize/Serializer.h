/*
 * Serializer.h
 *
 *  Created on: 31-Oct-2020
 *      Author: anantha
 */

#ifndef CORE_SERIALIZE_SERIALIZER_H_
#define CORE_SERIALIZE_SERIALIZER_H_

// Text archive that defines boost::archive::text_oarchive
// and boost::archive::text_iarchive
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

// XML archive that defines boost::archive::xml_oarchive
// and boost::archive::xml_iarchive
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>

namespace Golem {

class Serializer {
public:
    Serializer();
    virtual ~Serializer();


};

} /* namespace Golem */

#endif /* CORE_SERIALIZE_SERIALIZER_H_ */
