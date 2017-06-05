#ifndef TEST_H
#define TEST_H

#include <iostream>
#include "ignite/binary/binary.h"

namespace ignite
{
    namespace examples
    {
        struct Test
        {
            Test()
            {
                // No-op.
            }
            Test(const std::string& assetid, const std::string& asset_desc, const std::string& groupid) :
                assetid (assetid), asset_desc (asset_desc), groupid (groupid)
            {
                // No-op.
            }

            const std::string& GetAssetid () const
            {
              return assetid;
            }

            const std::string& GetAsset_desc () const
            {
              return asset_desc;
            }

            const std::string& GetGroupid () const
            {
                return groupid;
            }

            std::string ToString()
            {
                std::ostringstream oss;

                oss << "Address [street=" << assetid << ", zip=" << asset_desc<< "]";

                return oss.str();
            }

            std::string assetid;
            std::string asset_desc;
            std::string groupid;
        };
    }
}

namespace ignite
{
    namespace binary
    {
        template<>
        struct BinaryType<ignite::examples::Test>
        {
            static int32_t GetTypeId()
            {
                return GetBinaryStringHashCode("Test");
            }

            static void GetTypeName(std::string& dst)
            {
                dst = "Test";
            }

            static int32_t GetFieldId(const char* name)
            {
                return GetBinaryStringHashCode(name);
            }

            static int32_t GetHashCode(ignite::examples::Test obj)
            {
                return 0;
            }

            static bool IsNull(ignite::examples::Test obj)
            {
                return false;
            }

            static void GetNull(ignite::examples::Test& dst)
            {
                dst = ignite::examples::Test("", "","");
            }

            static void Write(BinaryWriter& writer, const ignite::examples::Test& obj)
            {
                writer.WriteString("assetid", obj.assetid);
                writer.WriteString ("asset_desc",obj.asset_desc);
                writer.WriteString ("groupid", obj.groupid);
            }

            static void Read(BinaryReader& reader, ignite::examples::Test& dst)
            {
                dst.assetid = reader.ReadString("assetid");
                dst.asset_desc = reader.ReadString ("asset_desc");
                dst.groupid = reader.ReadString ("groupid");
            }
        };
    }
}


#endif
