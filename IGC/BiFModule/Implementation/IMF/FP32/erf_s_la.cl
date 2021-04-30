/*========================== begin_copyright_notice ============================

Copyright (C) 2020-2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

#include "../imf.h"
#pragma OPENCL FP_CONTRACT OFF
#pragma float_control(precise,on)

#pragma float_control(precise,on)
typedef struct
{

    unsigned int _erf_tbl[1008];
    unsigned int _erf_tbl_exp223[504];

    unsigned int _AbsMask;
    unsigned int _One;
    unsigned int _SplitMask;
    unsigned int _iSignMask;
    unsigned int _MaxThreshold;
    unsigned int _TwoOverSqrtPi;
    unsigned int _SRound;
    unsigned int _TThreshold;
    unsigned int _U2Threshold;

    unsigned int _poly1_0;
    unsigned int _poly1_1;
    unsigned int _poly3_0;

    unsigned int _ep_poly1_0;
    unsigned int _gf_MaxThreshold_LA;
    unsigned int _gf_MaxThreshold_EP;
    unsigned int _gf_ep_poly_0;
    unsigned int _gf_ep_poly_1;
    unsigned int _gf_ep_poly_2;
    unsigned int _gf_ep_poly_3;
    unsigned int _gf_ep_poly_4;
    unsigned int _gf_ep_poly_5;

} __internal_serf_la_data_t;
static __constant __internal_serf_la_data_t __internal_serf_la_data = {

    {

     0x00000000u, 0x3f906ebbu,
     0x3c106dfau, 0x3f906c79u,
     0x3c906bb8u, 0x3f9065b4u,
     0x3cd89bf0u, 0x3f905a6cu,
     0x3d1062b2u, 0x3f904aa3u,
     0x3d3472eau, 0x3f90365au,
     0x3d587d7fu, 0x3f901d93u,
     0x3d7c8154u, 0x3f900050u,
     0x3d903ea4u, 0x3f8fde94u,
     0x3da2381fu, 0x3f8fb862u,
     0x3db42c8du, 0x3f8f8dbdu,
     0x3dc61b5fu, 0x3f8f5eabu,
     0x3dd80409u, 0x3f8f2b2eu,
     0x3de9e5fcu, 0x3f8ef34cu,
     0x3dfbc0adu, 0x3f8eb70au,
     0x3e06c9c8u, 0x3f8e766eu,
     0x3e0faf0du, 0x3f8e317du,
     0x3e188fe1u, 0x3f8de83eu,
     0x3e216bfeu, 0x3f8d9ab9u,
     0x3e2a4321u, 0x3f8d48f3u,
     0x3e331506u, 0x3f8cf2f5u,
     0x3e3be169u, 0x3f8c98c6u,
     0x3e44a808u, 0x3f8c3a6fu,
     0x3e4d68a1u, 0x3f8bd7f8u,
     0x3e5622f2u, 0x3f8b716cu,
     0x3e5ed6b9u, 0x3f8b06d2u,
     0x3e6783b7u, 0x3f8a9834u,
     0x3e7029aau, 0x3f8a259eu,
     0x3e78c855u, 0x3f89af18u,
     0x3e80afbcu, 0x3f8934afu,
     0x3e84f76bu, 0x3f88b66cu,
     0x3e893b19u, 0x3f88345du,
     0x3e8d7aa7u, 0x3f87ae8bu,
     0x3e91b5f8u, 0x3f872504u,
     0x3e95eceeu, 0x3f8697d3u,
     0x3e9a1f6bu, 0x3f860705u,
     0x3e9e4d54u, 0x3f8572a8u,
     0x3ea2768cu, 0x3f84dac8u,
     0x3ea69af8u, 0x3f843f72u,
     0x3eaaba7au, 0x3f83a0b6u,
     0x3eaed4fau, 0x3f82fe9fu,
     0x3eb2ea5cu, 0x3f82593eu,
     0x3eb6fa85u, 0x3f81b0a0u,
     0x3ebb055du, 0x3f8104d3u,
     0x3ebf0acau, 0x3f8055e8u,
     0x3ec30ab3u, 0x3f7f47d8u,
     0x3ec70501u, 0x3f7ddddfu,
     0x3ecaf99bu, 0x3f7c6e05u,
     0x3ecee869u, 0x3f7af867u,
     0x3ed2d156u, 0x3f797d26u,
     0x3ed6b44bu, 0x3f77fc62u,
     0x3eda9132u, 0x3f76763cu,
     0x3ede67f6u, 0x3f74ead4u,
     0x3ee23882u, 0x3f735a4cu,
     0x3ee602c2u, 0x3f71c4c4u,
     0x3ee9c6a2u, 0x3f702a5fu,
     0x3eed840eu, 0x3f6e8b3eu,
     0x3ef13af5u, 0x3f6ce783u,
     0x3ef4eb45u, 0x3f6b3f51u,
     0x3ef894eau, 0x3f6992c9u,
     0x3efc37d5u, 0x3f67e20fu,
     0x3effd3f5u, 0x3f662d45u,
     0x3f01b49du, 0x3f64748eu,
     0x3f037bcau, 0x3f62b80du,
     0x3f053f7bu, 0x3f60f7e5u,
     0x3f06ffa8u, 0x3f5f3439u,
     0x3f08bc4au, 0x3f5d6d2du,
     0x3f0a755au, 0x3f5ba2e3u,
     0x3f0c2ad3u, 0x3f59d57eu,
     0x3f0ddcaeu, 0x3f580523u,
     0x3f0f8ae6u, 0x3f5631f4u,
     0x3f113574u, 0x3f545c14u,
     0x3f12dc54u, 0x3f5283a7u,
     0x3f147f81u, 0x3f50a8cfu,
     0x3f161ef6u, 0x3f4ecbb1u,
     0x3f17baaeu, 0x3f4cec6du,
     0x3f1952a6u, 0x3f4b0b28u,
     0x3f1ae6dau, 0x3f492804u,
     0x3f1c7745u, 0x3f474323u,
     0x3f1e03e5u, 0x3f455ca8u,
     0x3f1f8cb7u, 0x3f4374b5u,
     0x3f2111b7u, 0x3f418b6bu,
     0x3f2292e4u, 0x3f3fa0eeu,
     0x3f24103au, 0x3f3db55eu,
     0x3f2589b9u, 0x3f3bc8dcu,
     0x3f26ff5du, 0x3f39db8au,
     0x3f287126u, 0x3f37ed89u,
     0x3f29df13u, 0x3f35fef8u,
     0x3f2b4922u, 0x3f340ff9u,
     0x3f2caf53u, 0x3f3220abu,
     0x3f2e11a4u, 0x3f30312eu,
     0x3f2f7017u, 0x3f2e41a1u,
     0x3f30caabu, 0x3f2c5223u,
     0x3f322160u, 0x3f2a62d3u,
     0x3f337437u, 0x3f2873cfu,
     0x3f34c32fu, 0x3f268534u,
     0x3f360e4cu, 0x3f249721u,
     0x3f37558cu, 0x3f22a9b3u,
     0x3f3898f3u, 0x3f20bd06u,
     0x3f39d881u, 0x3f1ed137u,
     0x3f3b1438u, 0x3f1ce661u,
     0x3f3c4c1bu, 0x3f1afca0u,
     0x3f3d802cu, 0x3f19140fu,
     0x3f3eb06cu, 0x3f172cc9u,
     0x3f3fdce0u, 0x3f1546e7u,
     0x3f410589u, 0x3f136284u,
     0x3f422a6bu, 0x3f117fb9u,
     0x3f434b89u, 0x3f0f9e9eu,
     0x3f4468e7u, 0x3f0dbf4cu,
     0x3f458287u, 0x3f0be1dbu,
     0x3f46986fu, 0x3f0a0662u,
     0x3f47aaa2u, 0x3f082cf7u,
     0x3f48b925u, 0x3f0655b1u,
     0x3f49c3fbu, 0x3f0480a6u,
     0x3f4acb29u, 0x3f02adebu,
     0x3f4bceb4u, 0x3f00dd96u,
     0x3f4ccea1u, 0x3efe1f73u,
     0x3f4dcaf4u, 0x3efa88d5u,
     0x3f4ec3b4u, 0x3ef6f777u,
     0x3f4fb8e5u, 0x3ef36b80u,
     0x3f50aa8du, 0x3eefe513u,
     0x3f5198b1u, 0x3eec6455u,
     0x3f528358u, 0x3ee8e968u,
     0x3f536a86u, 0x3ee5746du,
     0x3f544e43u, 0x3ee20584u,
     0x3f552e93u, 0x3ede9cccu,
     0x3f560b7eu, 0x3edb3a64u,
     0x3f56e50au, 0x3ed7de6au,
     0x3f57bb3du, 0x3ed488f8u,
     0x3f588e1eu, 0x3ed13a2bu,
     0x3f595db4u, 0x3ecdf21cu,
     0x3f5a2a05u, 0x3ecab0e4u,
     0x3f5af318u, 0x3ec7769bu,
     0x3f5bb8f4u, 0x3ec44359u,
     0x3f5c7ba1u, 0x3ec11733u,
     0x3f5d3b25u, 0x3ebdf23du,
     0x3f5df788u, 0x3ebad48du,
     0x3f5eb0d1u, 0x3eb7be35u,
     0x3f5f6707u, 0x3eb4af46u,
     0x3f601a32u, 0x3eb1a7d3u,
     0x3f60ca59u, 0x3eaea7eau,
     0x3f617784u, 0x3eabaf9au,
     0x3f6221bbu, 0x3ea8bef3u,
     0x3f62c905u, 0x3ea5d600u,
     0x3f636d69u, 0x3ea2f4ceu,
     0x3f640ef1u, 0x3ea01b68u,
     0x3f64ada3u, 0x3e9d49d9u,
     0x3f654987u, 0x3e9a8029u,
     0x3f65e2a6u, 0x3e97be62u,
     0x3f667906u, 0x3e95048bu,
     0x3f670cb1u, 0x3e9252aau,
     0x3f679daeu, 0x3e8fa8c5u,
     0x3f682c06u, 0x3e8d06e3u,
     0x3f68b7bfu, 0x3e8a6d05u,
     0x3f6940e2u, 0x3e87db31u,
     0x3f69c778u, 0x3e855168u,
     0x3f6a4b88u, 0x3e82cfadu,
     0x3f6acd1au, 0x3e805600u,
     0x3f6b4c36u, 0x3e7bc8c2u,
     0x3f6bc8e5u, 0x3e76f5a0u,
     0x3f6c432fu, 0x3e723298u,
     0x3f6cbb1bu, 0x3e6d7fa5u,
     0x3f6d30b1u, 0x3e68dcc1u,
     0x3f6da3fau, 0x3e6449e7u,
     0x3f6e14feu, 0x3e5fc70eu,
     0x3f6e83c4u, 0x3e5b542bu,
     0x3f6ef055u, 0x3e56f136u,
     0x3f6f5ab8u, 0x3e529e21u,
     0x3f6fc2f5u, 0x3e4e5adfu,
     0x3f702915u, 0x3e4a2761u,
     0x3f708d1fu, 0x3e460399u,
     0x3f70ef1bu, 0x3e41ef75u,
     0x3f714f11u, 0x3e3deae4u,
     0x3f71ad09u, 0x3e39f5d2u,
     0x3f72090au, 0x3e36102bu,
     0x3f72631cu, 0x3e3239dbu,
     0x3f72bb46u, 0x3e2e72cbu,
     0x3f731191u, 0x3e2abae4u,
     0x3f736604u, 0x3e27120fu,
     0x3f73b8a5u, 0x3e237833u,
     0x3f74097eu, 0x3e1fed36u,
     0x3f745895u, 0x3e1c70fdu,
     0x3f74a5f2u, 0x3e19036eu,
     0x3f74f19bu, 0x3e15a46du,
     0x3f753b98u, 0x3e1253dcu,
     0x3f7583f1u, 0x3e0f119fu,
     0x3f75caacu, 0x3e0bdd96u,
     0x3f760fd1u, 0x3e08b7a4u,
     0x3f765366u, 0x3e059fa9u,
     0x3f769573u, 0x3e029586u,
     0x3f76d5feu, 0x3dff3230u,
     0x3f77150fu, 0x3df95481u,
     0x3f7752abu, 0x3df391b9u,
     0x3f778edau, 0x3dede995u,
     0x3f77c9a2u, 0x3de85bd0u,
     0x3f78030au, 0x3de2e825u,
     0x3f783b18u, 0x3ddd8e4cu,
     0x3f7871d3u, 0x3dd84dfeu,
     0x3f78a741u, 0x3dd326f3u,
     0x3f78db68u, 0x3dce18e3u,
     0x3f790e50u, 0x3dc92385u,
     0x3f793ffcu, 0x3dc4468fu,
     0x3f797075u, 0x3dbf81b6u,
     0x3f799fbfu, 0x3dbad4b0u,
     0x3f79cde1u, 0x3db63f32u,
     0x3f79fae1u, 0x3db1c0f1u,
     0x3f7a26c4u, 0x3dad59a1u,
     0x3f7a518fu, 0x3da908f6u,
     0x3f7a7b4au, 0x3da4cea4u,
     0x3f7aa3f9u, 0x3da0aa5eu,
     0x3f7acba1u, 0x3d9c9bd9u,
     0x3f7af248u, 0x3d98a2c7u,
     0x3f7b17f4u, 0x3d94beddu,
     0x3f7b3ca9u, 0x3d90efcdu,
     0x3f7b606eu, 0x3d8d354bu,
     0x3f7b8346u, 0x3d898f0au,
     0x3f7ba537u, 0x3d85fcbfu,
     0x3f7bc646u, 0x3d827e1du,
     0x3f7be677u, 0x3d7e25afu,
     0x3f7c05d1u, 0x3d777546u,
     0x3f7c2456u, 0x3d70ea68u,
     0x3f7c420du, 0x3d6a847du,
     0x3f7c5ef9u, 0x3d6442f0u,
     0x3f7c7b1fu, 0x3d5e252au,
     0x3f7c9684u, 0x3d582a98u,
     0x3f7cb12bu, 0x3d5252a5u,
     0x3f7ccb1au, 0x3d4c9cbdu,
     0x3f7ce454u, 0x3d47084eu,
     0x3f7cfcddu, 0x3d4194c7u,
     0x3f7d14bau, 0x3d3c4196u,
     0x3f7d2befu, 0x3d370e2cu,
     0x3f7d427fu, 0x3d31f9fbu,
     0x3f7d586fu, 0x3d2d0474u,
     0x3f7d6dc2u, 0x3d282d0cu,
     0x3f7d827bu, 0x3d237336u,
     0x3f7d96a0u, 0x3d1ed669u,
     0x3f7daa32u, 0x3d1a561bu,
     0x3f7dbd36u, 0x3d15f1c6u,
     0x3f7dcfb0u, 0x3d11a8e1u,
     0x3f7de1a2u, 0x3d0d7ae9u,
     0x3f7df30fu, 0x3d09675au,
     0x3f7e03fdu, 0x3d056db0u,
     0x3f7e146cu, 0x3d018d6bu,
     0x3f7e2461u, 0x3cfb8c15u,
     0x3f7e33deu, 0x3cf42e22u,
     0x3f7e42e8u, 0x3ced0003u,
     0x3f7e517fu, 0x3ce600c0u,
     0x3f7e5fa9u, 0x3cdf2f67u,
     0x3f7e6d66u, 0x3cd88b05u,
     0x3f7e7abbu, 0x3cd212adu,
     0x3f7e87aau, 0x3ccbc574u,
     0x3f7e9435u, 0x3cc5a273u,
     0x3f7ea05fu, 0x3cbfa8c4u,
     0x3f7eac2bu, 0x3cb9d786u,
     0x3f7eb79au, 0x3cb42ddbu,
     0x3f7ec2b1u, 0x3caeaae6u,
     0x3f7ecd71u, 0x3ca94dcfu,
     0x3f7ed7dcu, 0x3ca415c2u,
     0x3f7ee1f4u, 0x3c9f01ecu,
     0x3f7eebbdu, 0x3c9a117fu,
     0x3f7ef537u, 0x3c9543aeu,
     0x3f7efe66u, 0x3c9097b1u,
     0x3f7f074bu, 0x3c8c0cc2u,
     0x3f7f0fe8u, 0x3c87a21fu,
     0x3f7f1840u, 0x3c83570au,
     0x3f7f2053u, 0x3c7e558au,
     0x3f7f2826u, 0x3c763931u,
     0x3f7f2fb8u, 0x3c6e579bu,
     0x3f7f370cu, 0x3c66af65u,
     0x3f7f3e23u, 0x3c5f3f2du,
     0x3f7f4500u, 0x3c58059cu,
     0x3f7f4ba4u, 0x3c51015fu,
     0x3f7f5211u, 0x3c4a3127u,
     0x3f7f5848u, 0x3c4393afu,
     0x3f7f5e4bu, 0x3c3d27b5u,
     0x3f7f641bu, 0x3c36ebffu,
     0x3f7f69bau, 0x3c30df57u,
     0x3f7f6f29u, 0x3c2b008eu,
     0x3f7f746au, 0x3c254e7bu,
     0x3f7f797fu, 0x3c1fc7fbu,
     0x3f7f7e67u, 0x3c1a6beeu,
     0x3f7f8326u, 0x3c15393du,
     0x3f7f87bbu, 0x3c102ed6u,
     0x3f7f8c29u, 0x3c0b4babu,
     0x3f7f9070u, 0x3c068eb5u,
     0x3f7f9492u, 0x3c01f6f1u,
     0x3f7f9890u, 0x3bfb06c5u,
     0x3f7f9c6bu, 0x3bf26625u,
     0x3f7fa024u, 0x3bea0a1du,
     0x3f7fa3bcu, 0x3be1f0d3u,
     0x3f7fa734u, 0x3bda1876u,
     0x3f7faa8du, 0x3bd27f42u,
     0x3f7fadc8u, 0x3bcb237au,
     0x3f7fb0e6u, 0x3bc4036cu,
     0x3f7fb3e8u, 0x3bbd1d6fu,
     0x3f7fb6cfu, 0x3bb66fe6u,
     0x3f7fb99cu, 0x3baff93bu,
     0x3f7fbc4fu, 0x3ba9b7e1u,
     0x3f7fbeeau, 0x3ba3aa56u,
     0x3f7fc16du, 0x3b9dcf20u,
     0x3f7fc3d9u, 0x3b9824ceu,
     0x3f7fc62eu, 0x3b92a9f7u,
     0x3f7fc86eu, 0x3b8d5d3cu,
     0x3f7fca99u, 0x3b883d46u,
     0x3f7fccb0u, 0x3b8348c6u,
     0x3f7fceb4u, 0x3b7cfce8u,
     0x3f7fd0a5u, 0x3b73ba24u,
     0x3f7fd283u, 0x3b6ac6d3u,
     0x3f7fd450u, 0x3b622096u,
     0x3f7fd60cu, 0x3b59c51du,
     0x3f7fd7b7u, 0x3b51b22au,
     0x3f7fd953u, 0x3b49e589u,
     0x3f7fdadfu, 0x3b425d18u,
     0x3f7fdc5cu, 0x3b3b16c2u,
     0x3f7fddccu, 0x3b341080u,
     0x3f7fdf2du, 0x3b2d4858u,
     0x3f7fe081u, 0x3b26bc5eu,
     0x3f7fe1c8u, 0x3b206ab2u,
     0x3f7fe303u, 0x3b1a5183u,
     0x3f7fe431u, 0x3b146f09u,
     0x3f7fe554u, 0x3b0ec18cu,
     0x3f7fe66cu, 0x3b09475du,
     0x3f7fe77au, 0x3b03fedau,
     0x3f7fe87du, 0x3afdccdcu,
     0x3f7fe975u, 0x3af3f919u,
     0x3f7fea65u, 0x3aea7f6cu,
     0x3f7feb4bu, 0x3ae15ce8u,
     0x3f7fec27u, 0x3ad88eb8u,
     0x3f7fecfcu, 0x3ad0121bu,
     0x3f7fedc8u, 0x3ac7e464u,
     0x3f7fee8cu, 0x3ac002f8u,
     0x3f7fef48u, 0x3ab86b52u,
     0x3f7feffdu, 0x3ab11afeu,
     0x3f7ff0aau, 0x3aaa0f9au,
     0x3f7ff151u, 0x3aa346d7u,
     0x3f7ff1f1u, 0x3a9cbe77u,
     0x3f7ff28au, 0x3a96744cu,
     0x3f7ff31eu, 0x3a90663bu,
     0x3f7ff3abu, 0x3a8a9237u,
     0x3f7ff433u, 0x3a84f643u,
     0x3f7ff4b5u, 0x3a7f20e7u,
     0x3f7ff532u, 0x3a74bdd2u,
     0x3f7ff5aau, 0x3a6abfa9u,
     0x3f7ff61du, 0x3a6122eau,
     0x3f7ff68bu, 0x3a57e42fu,
     0x3f7ff6f5u, 0x3a4f002cu,
     0x3f7ff75au, 0x3a4673afu,
     0x3f7ff7bbu, 0x3a3e3ba2u,
     0x3f7ff819u, 0x3a365507u,
     0x3f7ff872u, 0x3a2ebcf6u,
     0x3f7ff8c7u, 0x3a2770a1u,
     0x3f7ff919u, 0x3a206d52u,
     0x3f7ff968u, 0x3a19b066u,
     0x3f7ff9b3u, 0x3a133754u,
     0x3f7ff9fbu, 0x3a0cffa3u,
     0x3f7ffa40u, 0x3a0706f4u,
     0x3f7ffa82u, 0x3a014af8u,
     0x3f7ffac1u, 0x39f792eau,
     0x3f7ffafeu, 0x39ed0088u,
     0x3f7ffb38u, 0x39e2daa1u,
     0x3f7ffb6fu, 0x39d91d2du,
     0x3f7ffba5u, 0x39cfc44au,
     0x3f7ffbd7u, 0x39c6cc35u,
     0x3f7ffc08u, 0x39be314du,
     0x3f7ffc36u, 0x39b5f011u,
     0x3f7ffc63u, 0x39ae051cu,
     0x3f7ffc8eu, 0x39a66d2au,
     0x3f7ffcb6u, 0x399f2512u,
     0x3f7ffcddu, 0x399829c8u,
     0x3f7ffd02u, 0x3991785au,
     0x3f7ffd26u, 0x398b0df2u,
     0x3f7ffd48u, 0x3984e7d2u,
     0x3f7ffd68u, 0x397e06abu,
     0x3f7ffd87u, 0x3972bbdeu,
     0x3f7ffda5u, 0x3967ea53u,
     0x3f7ffdc1u, 0x395d8d4bu,
     0x3f7ffddcu, 0x3953a034u,
     0x3f7ffdf6u, 0x394a1ea5u,
     0x3f7ffe0fu, 0x3941045eu,
     0x3f7ffe27u, 0x39384d47u,
     0x3f7ffe3du, 0x392ff56du,
     0x3f7ffe53u, 0x3927f904u,
     0x3f7ffe67u, 0x39205461u,
     0x3f7ffe7bu, 0x391903feu,
     0x3f7ffe8du, 0x39120475u,
     0x3f7ffe9fu, 0x390b5281u,
     0x3f7ffeb0u, 0x3904eafcu,
     0x3f7ffec0u, 0x38fd95bdu,
     0x3f7ffed0u, 0x38f1de7au,
     0x3f7ffedfu, 0x38e6aa94u,
     0x3f7ffeedu, 0x38dbf4a3u,
     0x3f7ffefau, 0x38d1b776u,
     0x3f7fff07u, 0x38c7ee0eu,
     0x3f7fff13u, 0x38be939cu,
     0x3f7fff1fu, 0x38b5a381u,
     0x3f7fff2au, 0x38ad194eu,
     0x3f7fff34u, 0x38a4f0bcu,
     0x3f7fff3fu, 0x389d25b0u,
     0x3f7fff48u, 0x3895b43bu,
     0x3f7fff51u, 0x388e9890u,
     0x3f7fff5au, 0x3887cf0eu,
     0x3f7fff62u, 0x38815434u,
     0x3f7fff6au, 0x3876494du,
     0x3f7fff72u, 0x386a7a5au,
     0x3f7fff79u, 0x385f355eu,
     0x3f7fff80u, 0x38547466u,
     0x3f7fff86u, 0x384a31bfu,
     0x3f7fff8cu, 0x384067eeu,
     0x3f7fff92u, 0x383711b4u,
     0x3f7fff98u, 0x382e2a06u,
     0x3f7fff9du, 0x3825ac0eu,
     0x3f7fffa2u, 0x381d9329u,
     0x3f7fffa7u, 0x3815dae6u,
     0x3f7fffabu, 0x380e7f01u,
     0x3f7fffb0u, 0x38077b62u,
     0x3f7fffb4u, 0x3800cc21u,
     0x3f7fffb8u, 0x37f4daf4u,
     0x3f7fffbcu, 0x37e8b7acu,
     0x3f7fffbfu, 0x37dd2782u,
     0x3f7fffc2u, 0x37d223dcu,
     0x3f7fffc6u, 0x37c7a666u,
     0x3f7fffc9u, 0x37bda912u,
     0x3f7fffccu, 0x37b42611u,
     0x3f7fffceu, 0x37ab17d6u,
     0x3f7fffd1u, 0x37a2790fu,
     0x3f7fffd3u, 0x379a44a5u,
     0x3f7fffd6u, 0x379275b9u,
     0x3f7fffd8u, 0x378b07a2u,
     0x3f7fffdau, 0x3783f5e9u,
     0x3f7fffdcu, 0x377a7897u,
     0x3f7fffdeu, 0x376dad68u,
     0x3f7fffe0u, 0x37618278u,
     0x3f7fffe2u, 0x3755f04fu,
     0x3f7fffe3u, 0x374aefccu,
     0x3f7fffe5u, 0x37407a1du,
     0x3f7fffe6u, 0x373688bcu,
     0x3f7fffe8u, 0x372d1570u,
     0x3f7fffe9u, 0x37241a44u,
     0x3f7fffeau, 0x371b9188u,
     0x3f7fffebu, 0x371375cfu,
     0x3f7fffecu, 0x370bc1e7u,
     0x3f7fffeeu, 0x370470ddu,
     0x3f7fffefu, 0x36fafbecu,
     0x3f7fffefu, 0x36edc95bu,
     0x3f7ffff0u, 0x36e14167u,
     0x3f7ffff1u, 0x36d55bd6u,
     0x3f7ffff2u, 0x36ca10ceu,
     0x3f7ffff3u, 0x36bf58d1u,
     0x3f7ffff4u, 0x36b52cb9u,
     0x3f7ffff4u, 0x36ab85b5u,
     0x3f7ffff5u, 0x36a25d43u,
     0x3f7ffff5u, 0x3699ad31u,
     0x3f7ffff6u, 0x36916f95u,
     0x3f7ffff7u, 0x36899ecbu,
     0x3f7ffff7u, 0x36823575u,
     0x3f7ffff8u, 0x36765ce8u,
     0x3f7ffff8u, 0x366909ccu,
     0x3f7ffff9u, 0x365c684au,
     0x3f7ffff9u, 0x36506f88u,
     0x3f7ffff9u, 0x36451713u,
     0x3f7ffffau, 0x363a56e4u,
     0x3f7ffffau, 0x36302754u,
     0x3f7ffffau, 0x36268119u,
     0x3f7ffffbu, 0x361d5d43u,
     0x3f7ffffbu, 0x3614b538u,
     0x3f7ffffbu, 0x360c82b1u,
     0x3f7ffffcu, 0x3604bfb1u,
     0x3f7ffffcu, 0x35facd10u,
     0x3f7ffffcu, 0x35ece39bu,
     0x3f7ffffcu, 0x35dfb8b6u,
     0x3f7ffffdu, 0x35d34296u,
     0x3f7ffffdu, 0x35c777ecu,
     0x3f7ffffdu, 0x35bc4fdcu,
     0x3f7ffffdu, 0x35b1c1fcu,
     0x3f7ffffdu, 0x35a7c64bu,
     0x3f7ffffdu, 0x359e5531u,
     0x3f7ffffeu, 0x35956771u,
     0x3f7ffffeu, 0x358cf630u,
     0x3f7ffffeu, 0x3584fae8u,
     0x3f7ffffeu, 0x357adecbu,
     0x3f7ffffeu, 0x356c9b8fu,
     0x3f7ffffeu, 0x355f20efu,
     0x3f7ffffeu, 0x3552644fu,
     0x3f7ffffeu, 0x35465b9cu,
     0x3f7fffffu, 0x353afd47u,
     0x3f7fffffu, 0x3530403cu,
     0x3f7fffffu, 0x35261be0u,
     0x3f7fffffu, 0x351c8807u,
     0x3f7fffffu, 0x35137cf0u,
     0x3f7fffffu, 0x350af341u,
     0x3f7fffffu, 0x3502e402u,
     0x3f7fffffu, 0x34f6912au,
     0x3f7fffffu, 0x34e8356bu,
     0x3f7fffffu, 0x34daa8e4u,
     0x3f7fffffu, 0x34cde050u,
     0x3f7fffffu, 0x34c1d100u,
     0x3f7fffffu, 0x34b670d5u,
     0x3f7fffffu, 0x34abb639u,
     0x3f7fffffu, 0x34a19816u,
     0x3f7fffffu, 0x34980dd1u,
     0x3f7fffffu, 0x348f0f43u,
     0x3f7fffffu, 0x348694b3u,
     0x3f800000u, 0x347d2da8u,
     0x3f800000u, 0x346e1d72u,
     },

    {
     0x00000000u,
     0x3c106dfau,
     0x3c906bb8u,
     0x3cd89bf0u,
     0x3d1062b2u,
     0x3d3472eau,
     0x3d587d7fu,
     0x3d7c8154u,
     0x3d903ea4u,
     0x3da2381fu,
     0x3db42c8du,
     0x3dc61b5fu,
     0x3dd80409u,
     0x3de9e5fcu,
     0x3dfbc0adu,
     0x3e06c9c8u,
     0x3e0faf0du,
     0x3e188fe1u,
     0x3e216bfeu,
     0x3e2a4321u,
     0x3e331506u,
     0x3e3be169u,
     0x3e44a808u,
     0x3e4d68a1u,
     0x3e5622f2u,
     0x3e5ed6b9u,
     0x3e6783b7u,
     0x3e7029aau,
     0x3e78c855u,
     0x3e80afbcu,
     0x3e84f76bu,
     0x3e893b19u,
     0x3e8d7aa7u,
     0x3e91b5f8u,
     0x3e95eceeu,
     0x3e9a1f6bu,
     0x3e9e4d54u,
     0x3ea2768cu,
     0x3ea69af8u,
     0x3eaaba7au,
     0x3eaed4fau,
     0x3eb2ea5cu,
     0x3eb6fa85u,
     0x3ebb055du,
     0x3ebf0acau,
     0x3ec30ab3u,
     0x3ec70501u,
     0x3ecaf99bu,
     0x3ecee869u,
     0x3ed2d156u,
     0x3ed6b44bu,
     0x3eda9132u,
     0x3ede67f6u,
     0x3ee23882u,
     0x3ee602c2u,
     0x3ee9c6a2u,
     0x3eed840eu,
     0x3ef13af5u,
     0x3ef4eb45u,
     0x3ef894eau,
     0x3efc37d5u,
     0x3effd3f5u,
     0x3f01b49du,
     0x3f037bcau,
     0x3f053f7bu,
     0x3f06ffa8u,
     0x3f08bc4au,
     0x3f0a755au,
     0x3f0c2ad3u,
     0x3f0ddcaeu,
     0x3f0f8ae6u,
     0x3f113574u,
     0x3f12dc54u,
     0x3f147f81u,
     0x3f161ef6u,
     0x3f17baaeu,
     0x3f1952a6u,
     0x3f1ae6dau,
     0x3f1c7745u,
     0x3f1e03e5u,
     0x3f1f8cb7u,
     0x3f2111b7u,
     0x3f2292e4u,
     0x3f24103au,
     0x3f2589b9u,
     0x3f26ff5du,
     0x3f287126u,
     0x3f29df13u,
     0x3f2b4922u,
     0x3f2caf53u,
     0x3f2e11a4u,
     0x3f2f7017u,
     0x3f30caabu,
     0x3f322160u,
     0x3f337437u,
     0x3f34c32fu,
     0x3f360e4cu,
     0x3f37558cu,
     0x3f3898f3u,
     0x3f39d881u,
     0x3f3b1438u,
     0x3f3c4c1bu,
     0x3f3d802cu,
     0x3f3eb06cu,
     0x3f3fdce0u,
     0x3f410589u,
     0x3f422a6bu,
     0x3f434b89u,
     0x3f4468e7u,
     0x3f458287u,
     0x3f46986fu,
     0x3f47aaa2u,
     0x3f48b925u,
     0x3f49c3fbu,
     0x3f4acb29u,
     0x3f4bceb4u,
     0x3f4ccea1u,
     0x3f4dcaf4u,
     0x3f4ec3b4u,
     0x3f4fb8e5u,
     0x3f50aa8du,
     0x3f5198b1u,
     0x3f528358u,
     0x3f536a86u,
     0x3f544e43u,
     0x3f552e93u,
     0x3f560b7eu,
     0x3f56e50au,
     0x3f57bb3du,
     0x3f588e1eu,
     0x3f595db4u,
     0x3f5a2a05u,
     0x3f5af318u,
     0x3f5bb8f4u,
     0x3f5c7ba1u,
     0x3f5d3b25u,
     0x3f5df788u,
     0x3f5eb0d1u,
     0x3f5f6707u,
     0x3f601a32u,
     0x3f60ca59u,
     0x3f617784u,
     0x3f6221bbu,
     0x3f62c905u,
     0x3f636d69u,
     0x3f640ef1u,
     0x3f64ada3u,
     0x3f654987u,
     0x3f65e2a6u,
     0x3f667906u,
     0x3f670cb1u,
     0x3f679daeu,
     0x3f682c06u,
     0x3f68b7bfu,
     0x3f6940e2u,
     0x3f69c778u,
     0x3f6a4b88u,
     0x3f6acd1au,
     0x3f6b4c36u,
     0x3f6bc8e5u,
     0x3f6c432fu,
     0x3f6cbb1bu,
     0x3f6d30b1u,
     0x3f6da3fau,
     0x3f6e14feu,
     0x3f6e83c4u,
     0x3f6ef055u,
     0x3f6f5ab8u,
     0x3f6fc2f5u,
     0x3f702915u,
     0x3f708d1fu,
     0x3f70ef1bu,
     0x3f714f11u,
     0x3f71ad09u,
     0x3f72090au,
     0x3f72631cu,
     0x3f72bb46u,
     0x3f731191u,
     0x3f736604u,
     0x3f73b8a5u,
     0x3f74097eu,
     0x3f745895u,
     0x3f74a5f2u,
     0x3f74f19bu,
     0x3f753b98u,
     0x3f7583f1u,
     0x3f75caacu,
     0x3f760fd1u,
     0x3f765366u,
     0x3f769573u,
     0x3f76d5feu,
     0x3f77150fu,
     0x3f7752abu,
     0x3f778edau,
     0x3f77c9a2u,
     0x3f78030au,
     0x3f783b18u,
     0x3f7871d3u,
     0x3f78a741u,
     0x3f78db68u,
     0x3f790e50u,
     0x3f793ffcu,
     0x3f797075u,
     0x3f799fbfu,
     0x3f79cde1u,
     0x3f79fae1u,
     0x3f7a26c4u,
     0x3f7a518fu,
     0x3f7a7b4au,
     0x3f7aa3f9u,
     0x3f7acba1u,
     0x3f7af248u,
     0x3f7b17f4u,
     0x3f7b3ca9u,
     0x3f7b606eu,
     0x3f7b8346u,
     0x3f7ba537u,
     0x3f7bc646u,
     0x3f7be677u,
     0x3f7c05d1u,
     0x3f7c2456u,
     0x3f7c420du,
     0x3f7c5ef9u,
     0x3f7c7b1fu,
     0x3f7c9684u,
     0x3f7cb12bu,
     0x3f7ccb1au,
     0x3f7ce454u,
     0x3f7cfcddu,
     0x3f7d14bau,
     0x3f7d2befu,
     0x3f7d427fu,
     0x3f7d586fu,
     0x3f7d6dc2u,
     0x3f7d827bu,
     0x3f7d96a0u,
     0x3f7daa32u,
     0x3f7dbd36u,
     0x3f7dcfb0u,
     0x3f7de1a2u,
     0x3f7df30fu,
     0x3f7e03fdu,
     0x3f7e146cu,
     0x3f7e2461u,
     0x3f7e33deu,
     0x3f7e42e8u,
     0x3f7e517fu,
     0x3f7e5fa9u,
     0x3f7e6d66u,
     0x3f7e7abbu,
     0x3f7e87aau,
     0x3f7e9435u,
     0x3f7ea05fu,
     0x3f7eac2bu,
     0x3f7eb79au,
     0x3f7ec2b1u,
     0x3f7ecd71u,
     0x3f7ed7dcu,
     0x3f7ee1f4u,
     0x3f7eebbdu,
     0x3f7ef537u,
     0x3f7efe66u,
     0x3f7f074bu,
     0x3f7f0fe8u,
     0x3f7f1840u,
     0x3f7f2053u,
     0x3f7f2826u,
     0x3f7f2fb8u,
     0x3f7f370cu,
     0x3f7f3e23u,
     0x3f7f4500u,
     0x3f7f4ba4u,
     0x3f7f5211u,
     0x3f7f5848u,
     0x3f7f5e4bu,
     0x3f7f641bu,
     0x3f7f69bau,
     0x3f7f6f29u,
     0x3f7f746au,
     0x3f7f797fu,
     0x3f7f7e67u,
     0x3f7f8326u,
     0x3f7f87bbu,
     0x3f7f8c29u,
     0x3f7f9070u,
     0x3f7f9492u,
     0x3f7f9890u,
     0x3f7f9c6bu,
     0x3f7fa024u,
     0x3f7fa3bcu,
     0x3f7fa734u,
     0x3f7faa8du,
     0x3f7fadc8u,
     0x3f7fb0e6u,
     0x3f7fb3e8u,
     0x3f7fb6cfu,
     0x3f7fb99cu,
     0x3f7fbc4fu,
     0x3f7fbeeau,
     0x3f7fc16du,
     0x3f7fc3d9u,
     0x3f7fc62eu,
     0x3f7fc86eu,
     0x3f7fca99u,
     0x3f7fccb0u,
     0x3f7fceb4u,
     0x3f7fd0a5u,
     0x3f7fd283u,
     0x3f7fd450u,
     0x3f7fd60cu,
     0x3f7fd7b7u,
     0x3f7fd953u,
     0x3f7fdadfu,
     0x3f7fdc5cu,
     0x3f7fddccu,
     0x3f7fdf2du,
     0x3f7fe081u,
     0x3f7fe1c8u,
     0x3f7fe303u,
     0x3f7fe431u,
     0x3f7fe554u,
     0x3f7fe66cu,
     0x3f7fe77au,
     0x3f7fe87du,
     0x3f7fe975u,
     0x3f7fea65u,
     0x3f7feb4bu,
     0x3f7fec27u,
     0x3f7fecfcu,
     0x3f7fedc8u,
     0x3f7fee8cu,
     0x3f7fef48u,
     0x3f7feffdu,
     0x3f7ff0aau,
     0x3f7ff151u,
     0x3f7ff1f1u,
     0x3f7ff28au,
     0x3f7ff31eu,
     0x3f7ff3abu,
     0x3f7ff433u,
     0x3f7ff4b5u,
     0x3f7ff532u,
     0x3f7ff5aau,
     0x3f7ff61du,
     0x3f7ff68bu,
     0x3f7ff6f5u,
     0x3f7ff75au,
     0x3f7ff7bbu,
     0x3f7ff819u,
     0x3f7ff872u,
     0x3f7ff8c7u,
     0x3f7ff919u,
     0x3f7ff968u,
     0x3f7ff9b3u,
     0x3f7ff9fbu,
     0x3f7ffa40u,
     0x3f7ffa82u,
     0x3f7ffac1u,
     0x3f7ffafeu,
     0x3f7ffb38u,
     0x3f7ffb6fu,
     0x3f7ffba5u,
     0x3f7ffbd7u,
     0x3f7ffc08u,
     0x3f7ffc36u,
     0x3f7ffc63u,
     0x3f7ffc8eu,
     0x3f7ffcb6u,
     0x3f7ffcddu,
     0x3f7ffd02u,
     0x3f7ffd26u,
     0x3f7ffd48u,
     0x3f7ffd68u,
     0x3f7ffd87u,
     0x3f7ffda5u,
     0x3f7ffdc1u,
     0x3f7ffddcu,
     0x3f7ffdf6u,
     0x3f7ffe0fu,
     0x3f7ffe27u,
     0x3f7ffe3du,
     0x3f7ffe53u,
     0x3f7ffe67u,
     0x3f7ffe7bu,
     0x3f7ffe8du,
     0x3f7ffe9fu,
     0x3f7ffeb0u,
     0x3f7ffec0u,
     0x3f7ffed0u,
     0x3f7ffedfu,
     0x3f7ffeedu,
     0x3f7ffefau,
     0x3f7fff07u,
     0x3f7fff13u,
     0x3f7fff1fu,
     0x3f7fff2au,
     0x3f7fff34u,
     0x3f7fff3fu,
     0x3f7fff48u,
     0x3f7fff51u,
     0x3f7fff5au,
     0x3f7fff62u,
     0x3f7fff6au,
     0x3f7fff72u,
     0x3f7fff79u,
     0x3f7fff80u,
     0x3f7fff86u,
     0x3f7fff8cu,
     0x3f7fff92u,
     0x3f7fff98u,
     0x3f7fff9du,
     0x3f7fffa2u,
     0x3f7fffa7u,
     0x3f7fffabu,
     0x3f7fffb0u,
     0x3f7fffb4u,
     0x3f7fffb8u,
     0x3f7fffbcu,
     0x3f7fffbfu,
     0x3f7fffc2u,
     0x3f7fffc6u,
     0x3f7fffc9u,
     0x3f7fffccu,
     0x3f7fffceu,
     0x3f7fffd1u,
     0x3f7fffd3u,
     0x3f7fffd6u,
     0x3f7fffd8u,
     0x3f7fffdau,
     0x3f7fffdcu,
     0x3f7fffdeu,
     0x3f7fffe0u,
     0x3f7fffe2u,
     0x3f7fffe3u,
     0x3f7fffe5u,
     0x3f7fffe6u,
     0x3f7fffe8u,
     0x3f7fffe9u,
     0x3f7fffeau,
     0x3f7fffebu,
     0x3f7fffecu,
     0x3f7fffeeu,
     0x3f7fffefu,
     0x3f7fffefu,
     0x3f7ffff0u,
     0x3f7ffff1u,
     0x3f7ffff2u,
     0x3f7ffff3u,
     0x3f7ffff4u,
     0x3f7ffff4u,
     0x3f7ffff5u,
     0x3f7ffff5u,
     0x3f7ffff6u,
     0x3f7ffff7u,
     0x3f7ffff7u,
     0x3f7ffff8u,
     0x3f7ffff8u,
     0x3f7ffff9u,
     0x3f7ffff9u,
     0x3f7ffff9u,
     0x3f7ffffau,
     0x3f7ffffau,
     0x3f7ffffau,
     0x3f7ffffbu,
     0x3f7ffffbu,
     0x3f7ffffbu,
     0x3f7ffffcu,
     0x3f7ffffcu,
     0x3f7ffffcu,
     0x3f7ffffcu,
     0x3f7ffffdu,
     0x3f7ffffdu,
     0x3f7ffffdu,
     0x3f7ffffdu,
     0x3f7ffffdu,
     0x3f7ffffdu,
     0x3f7ffffeu,
     0x3f7ffffeu,
     0x3f7ffffeu,
     0x3f7ffffeu,
     0x3f7ffffeu,
     0x3f7ffffeu,
     0x3f7ffffeu,
     0x3f7ffffeu,
     0x3f7fffffu,
     0x3f7fffffu,
     0x3f7fffffu,
     0x3f7fffffu,
     0x3f7fffffu,
     0x3f7fffffu,
     0x3f7fffffu,
     0x3f7fffffu,
     0x3f7fffffu,
     0x3f7fffffu,
     0x3f7fffffu,
     0x3f7fffffu,
     0x3f7fffffu,
     0x3f7fffffu,
     0x3f7fffffu,
     0x3f7fffffu,
     0x3f7fffffu,
     0x3f7fffffu,
     0x3f800000u,
     0x3f800000u,
     },

    0x7fffffffu,
    0x3f800000u,
    0x00001fffu,
    0x80000000u,
    0x407b8000u,
    0x3f906ebbu,
    0x47800000u,
    0x3ce00000u,
    0x2f800000u,

    0x3f2aaab3u,
    0xbf800005u,
    0xbeaaaadeu,

    0xbf80000au,

    0x41558c5au,
    0x40d74e66u,
    0x3f87f527u,
    0xbe34718du,
    0x3d175fffu,
    0xbbaf8d5du,
    0x39f00702u,
    0xb78f18f8u,

};

float __ocl_svml_erff (float a)
{

    float va1;
    float vr1;
    unsigned int vm;

    float r;

    va1 = a;;

    {

        float _AbsMask;
        float _MaxThreshold;
        float _SRound;

        float _poly1_0;
        float _poly1_1;
        float _poly3_0;

        float Sign;
        float Xa;
        float X;
        float X0;
        float T;
        float Diff;
        unsigned int Index;

        float P1;
        float P3;
        float D2;
        float THL[2];
        float _Exp_H_D;
        float _Erf_H;
        _AbsMask = as_float (__internal_serf_la_data._AbsMask);
        Xa = as_float ((as_uint (va1) & as_uint (_AbsMask)));

        Sign = as_float ((as_uint (Xa) ^ as_uint (va1)));

        _MaxThreshold = as_float (__internal_serf_la_data._MaxThreshold);
        X = ((Xa < _MaxThreshold) ? Xa : _MaxThreshold);
        {
            float _U2Threshold;
            float UMask;
            float dIndex;
            _SRound = as_float (__internal_serf_la_data._SRound);
            dIndex = (X + _SRound);
            _U2Threshold = as_float (__internal_serf_la_data._U2Threshold);
            UMask = as_float (((unsigned int) (-(signed int) (X > _U2Threshold))));
            X0 = (dIndex - _SRound);
            Diff = (X - X0);
            D2 = as_float ((as_uint (Diff) & as_uint (UMask)));
            Index = as_uint (dIndex);
            Index = ((unsigned int) (Index) << (3));
            T = (Diff * X0);
        };

        THL[0] = as_float (((__constant unsigned int *) ((__constant char *) (&__internal_serf_la_data._erf_tbl[0]) - 0x3c000000))[Index >> 2]);
        THL[1] = as_float (((__constant unsigned int *) ((__constant char *) (&__internal_serf_la_data._erf_tbl[0]) - 0x3c000000))[(Index >> 2) + 1]);

        _poly3_0 = as_float (__internal_serf_la_data._poly3_0);

        Diff = ((Diff < Xa) ? Diff : Xa);

        D2 = (D2 * D2);
        P1 = __builtin_spirv_OpenCL_fma_f32_f32_f32 (_poly3_0, D2, -(T));

        vm = 0;

        P1 = __builtin_spirv_OpenCL_fma_f32_f32_f32 (P1, Diff, Diff);

        P1 = __builtin_spirv_OpenCL_fma_f32_f32_f32 (P1, THL[1], THL[0]);

        vr1 = as_float ((as_uint (P1) | as_uint (Sign)));
        {
            float _sIsNan;
            _sIsNan = as_float (((unsigned int) (-(signed int) ((va1 != va1) | (va1 != va1)))));
            vr1 = as_float ((((~as_uint (_sIsNan)) & as_uint (vr1)) | (as_uint (_sIsNan) & as_uint (va1))));
        }
    }

    ;
    r = vr1;;

    return r;

}
