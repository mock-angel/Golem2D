/*
 * EventRunner.h
 *
 *  Created on: 02-Nov-2020
 *      Author: anantha
 */

#ifndef CORE_EVENT_RAWEVENTPROCESSOR_H_
#define CORE_EVENT_RAWEVENTPROCESSOR_H_

namespace Golem {

class RawEventProcessor {
public:
    RawEventProcessor();
    virtual ~RawEventProcessor();

    void process();


};

} /* namespace Golem */

#endif /* CORE_EVENT_RAWEVENTPROCESSOR_H_ */
