/**
 * @file
 * Declares the Linux fips fact resolver.
 */
#pragma once

#include "../resolvers/fips_resolver.hpp"

namespace facter { namespace facts { namespace linux {

    /**
     * Responsible for resolving fips-related facts.
     */
    struct fips_resolver : resolvers::fips_resolver
    {
     //protected:
	/**
	 * The check consists of the following.
	 *   (1) Examining the contents of /proc/sys/crypto/fips_enabled. If it is 1
         *   then fips mode is enabled.
	 */ 
        
        virtual data collect_data(collection& facts) override;
    };

}}}  // namespace facter::facts::linux
