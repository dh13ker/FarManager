﻿// validator: no-include-guards
/*
disabled_warnings.hpp
*/
/*
Copyright © 2015 Far Group
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. The name of the authors may not be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifdef _MSC_VER
// some warnings are not exist in older VC versions, no sense to care about them
#pragma warning(disable: 4616) // https://msdn.microsoft.com/en-us/library/t7ab6xtd.aspx #pragma warning : warning number 'number' not a valid compiler warning
#pragma warning(disable: 4619) // https://msdn.microsoft.com/en-us/library/tacee08d.aspx #pragma warning : there is no warning number 'number'

#ifdef DISABLE_WARNINGS_IN_STD_HEADERS
// these warnings are triggered in the standard headers ONLY
#pragma warning(disable: 4091) // https://msdn.microsoft.com/en-us/library/eehkcz60.aspx 'typedef ': ignored on left of 'type' when no variable is declared
#pragma warning(disable: 4265) // https://msdn.microsoft.com/en-us/library/wzxffy8c.aspx 'class' : class has virtual functions, but destructor is not virtual
#pragma warning(disable: 4668) // https://msdn.microsoft.com/en-us/library/4dt9kyhy.aspx 'symbol' is not defined as a preprocessor macro, replacing with '0' for 'directives'
#pragma warning(disable: 4768) // no page                                                __declspec attributes before linkage specification are ignored
#pragma warning(disable: 4774) // no page                                                'function' : format string expected in argument 'number' is not a string literal
#pragma warning(disable: 4917) // https://msdn.microsoft.com/en-us/library/3w98z1xh.aspx 'declarator' : a GUID can only be associated with a class, interface or namespace
#pragma warning(disable: 4987) // no page                                                nonstandard extension used: 'throw (...)'
#pragma warning(disable: 4996) // https://msdn.microsoft.com/en-us/library/ttcz0bys.aspx The compiler encountered a deprecated declaration
#pragma warning(disable: 4582) // no page                                                'class': constructor is not implicitly called
#pragma warning(disable: 4583) // no page                                                'class': destructor is not implicitly called
#else
// these in the rest of the code as well
#pragma warning(disable: 4061) // https://msdn.microsoft.com/en-us/library/96f5t7fy.aspx enumerator 'identifier' in switch of enum 'enumeration' is not explicitly handled by a case label
#pragma warning(disable: 4100) // https://msdn.microsoft.com/en-us/library/26kb9fy0.aspx 'identifier' : unreferenced formal parameter
#pragma warning(disable: 4201) // https://msdn.microsoft.com/en-us/library/c89bw853.aspx nonstandard extension used : nameless struct/union
#pragma warning(disable: 4242) // https://msdn.microsoft.com/en-us/library/3hca13eh.aspx 'identifier' : conversion from 'type1' to 'type2', possible loss of data
#pragma warning(disable: 4244) // https://msdn.microsoft.com/en-us/library/th7a07tz.aspx 'conversion' conversion from 'type1' to 'type2', possible loss of data
#pragma warning(disable: 4245) // https://msdn.microsoft.com/en-us/library/e9s7thk1.aspx 'conversion' : conversion from 'type1' to 'type2', signed/unsigned mismatch
#pragma warning(disable: 4250) // https://msdn.microsoft.com/en-us/library/6b3sy7ae.aspx 'class1' : inherits 'class2::member' via dominance
#pragma warning(disable: 4324) // https://msdn.microsoft.com/en-us/library/92fdk6xx.aspx 'struct_name' : structure was padded due to __declspec(align())
#pragma warning(disable: 4355) // https://msdn.microsoft.com/en-us/library/3c594ae3.aspx 'this' : used in base member initializer list
#pragma warning(disable: 4365) // https://msdn.microsoft.com/en-us/library/ms173683.aspx 'action' : conversion from 'type_1' to 'type_2', signed/unsigned mismatch
#pragma warning(disable: 4371) // no page                                                layout of class may have changed from a previous version of the compiler due to better packing of member 'member'
#pragma warning(disable: 4373) // https://msdn.microsoft.com/en-us/library/bb384874.aspx 'function': virtual function overrides 'function', previous versions of the compiler did not override when parameters only differed by const/volatile qualifiers
#pragma warning(disable: 4435) // https://msdn.microsoft.com/en-us/library/jj155806.aspx 'class1' : Object layout under /vd2 will change due to virtual base 'class2'
#pragma warning(disable: 4464) // no page                                                relative include path contains '..'
#pragma warning(disable: 4503) // https://msdn.microsoft.com/en-us/library/074af4b6.aspx 'identifier' : decorated name length exceeded, name was truncated
#pragma warning(disable: 4512) // https://msdn.microsoft.com/en-us/library/hsyx7kbz.aspx 'class' : assignment operator could not be generated
#pragma warning(disable: 4514) // https://msdn.microsoft.com/en-us/library/cw9x3tcf.aspx 'function' : unreferenced inline function has been removed
#pragma warning(disable: 4571) // https://msdn.microsoft.com/en-us/library/55s8esw4.aspx Informational: catch(...) semantics changed since Visual C++ 7.1; structured exceptions (SEH) are no longer caught
#pragma warning(disable: 4574) // no page                                                'identifier' is defined to be '0': did you mean to use '#if identifier'?
#pragma warning(disable: 4623) // https://msdn.microsoft.com/en-us/library/8dk81ahy.aspx 'derived class' : default constructor was implicitly defined as deleted because a base class default constructor is inaccessible or deleted
#pragma warning(disable: 4625) // https://msdn.microsoft.com/en-us/library/306zwa5e.aspx 'derived class' : copy constructor could not be generated because a base class copy constructor is inaccessible
#pragma warning(disable: 4626) // https://msdn.microsoft.com/en-us/library/6ay4xcyd.aspx 'derived class' : assignment operator could not be generated because a base class assignment operator is inaccessible
#pragma warning(disable: 4640) // https://msdn.microsoft.com/en-us/library/4f5c8560.aspx 'instance' : construction of local static object is not thread-safe
#pragma warning(disable: 4670) // https://msdn.microsoft.com/en-us/library/d8stxx4t.aspx identifier' : this base class is inaccessible
#pragma warning(disable: 4673) // https://msdn.microsoft.com/en-us/library/32y577d8.aspx throwing 'identifier' the following types will not be considered at the catch site
#pragma warning(disable: 4710) // https://msdn.microsoft.com/en-us/library/yd3056cz.aspx 'function' : function not inlined
#pragma warning(disable: 4711) // https://msdn.microsoft.com/en-us/library/k402bt7y.aspx function 'function' selected for inline expansion
#pragma warning(disable: 4770) // no page                                                partially validated enum 'name' used as index
#pragma warning(disable: 4738) // https://msdn.microsoft.com/en-us/library/c24hdbz6.aspx storing 32-bit float result in memory, possible loss of performance
#pragma warning(disable: 4814) // no page                                                in C++14 'constexpr' will not imply 'const'; consider explicitly specifying 'const'
#pragma warning(disable: 4820) // https://msdn.microsoft.com/en-us/library/t7khkyth.aspx 'bytes' bytes padding added after construct 'member_name'
#pragma warning(disable: 4868) // https://msdn.microsoft.com/en-us/library/mt656772.aspx file(line_number)' compiler may not enforce left-to-right evaluation order in braced initializer list
#pragma warning(disable: 5025) // no page                                                'class': move assignment operator was implicitly defined as deleted
#pragma warning(disable: 5026) // no page                                                'class': move constructor was implicitly defined as deleted because a base class move constructor is inaccessible or deleted
#pragma warning(disable: 5027) // no page                                                'class': move assignment operator was implicitly defined as deleted because a base class move assignment operator is inaccessible or deleted
#pragma warning(disable: 5030) // no page                                                attribute 'attribute' is not recognized
#pragma warning(disable: 5039) // no page                                                'function': pointer or reference to potentially throwing function passed to extern C function under -EHc. Undefined behavior may occur if this function throws an exception.
#pragma warning(disable: 5045) // no page                                                Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified
#endif

#ifdef __clang__
#pragma clang diagnostic ignored "-Wunknown-warning-option"

// TODO: some of these might be useful
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wconversion"
#pragma clang diagnostic ignored "-Wcovered-switch-default"
#pragma clang diagnostic ignored "-Wctad-maybe-unsupported"
#pragma clang diagnostic ignored "-Wdeprecated-this-capture"
#pragma clang diagnostic ignored "-Wdisabled-macro-expansion"
#pragma clang diagnostic ignored "-Wenum-compare"
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#pragma clang diagnostic ignored "-Wgnu-anonymous-struct"
#pragma clang diagnostic ignored "-Wgnu-zero-variadic-macro-arguments"
#pragma clang diagnostic ignored "-Winvalid-token-paste"
#pragma clang diagnostic ignored "-Wkeyword-macro"
#pragma clang diagnostic ignored "-Wlanguage-extension-token"
#pragma clang diagnostic ignored "-Wmicrosoft"
#pragma clang diagnostic ignored "-Wmissing-braces"
#pragma clang diagnostic ignored "-Wmissing-field-initializers"
#pragma clang diagnostic ignored "-Wnested-anon-types"
#pragma clang diagnostic ignored "-Wnonportable-system-include-path"
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wrange-loop-analysis"
#pragma clang diagnostic ignored "-Wreturn-std-move-in-c++11"
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#pragma clang diagnostic ignored "-Wshadow-field-in-constructor"
#pragma clang diagnostic ignored "-Wshadow-field"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wswitch-enum"
#pragma clang diagnostic ignored "-Wundefined-func-template"
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma clang diagnostic ignored "-Wunused-parameter"
#endif

#endif
