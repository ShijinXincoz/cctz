#include <iostream>
#include "ignite/ignite.h"
#include "ignite/ignition.h"
#include "ignite/examples/test.h"

using namespace ignite;
using namespace cache;
using namespace std;
using namespace examples;

int main()
{
    IgniteConfiguration cfg;
    cfg.springCfgPath = "apache-ignite-fabric-2.0.0-bin/cassandra-config.xml";
    Ignite grid = Ignition::Start(cfg);
    Cache<Test, Test> cache = grid.GetCache<Test, Test>("cache1");
    Test obj;
    Test key;
    key.assetid = "My Key";
    obj.asset_desc = "hello";
    obj.groupid = "hai";
    cache.Put (key, obj);
    IgniteError err;
    cache.LoadCache ();
    std::cin.get();
    Test test = cache.Get (key, err);
    cout << "Ignite \t" << test.assetid << "\t" << test.asset_desc << " groupId" << test.groupid << endl;
    return 0;
}
