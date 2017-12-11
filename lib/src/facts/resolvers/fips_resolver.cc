#include <internal/facts/resolvers/fips_resolver.hpp>
#include <facter/facts/collection.hpp>
#include <facter/facts/fact.hpp>
#include <facter/facts/map_value.hpp>
#include <facter/facts/scalar_value.hpp>

using namespace std;
using namespace facter::facts;

namespace facter { namespace facts { namespace resolvers {

    fips_resolver::fips_resolver() :
        resolver("fips", {fact::in_fips_mode})
    {
    }

    void fips_resolver::resolve(collection& facts)
    {
        data result = collect_data(facts);
        // auto data = collect_data(facts);
        if (result.is_fips_mode_enabled)
            facts.add(fact::in_fips_mode, make_value<boolean_value>(result.is_fips_mode_enabled));
    }

}}}  // namespace facter::facts::resolvers
