#ifndef BOOST_RESULT_OF_S_HPP
#define BOOST_RESULT_OF_S_HPP

#include <boost/predef.h>
#include <boost/utility/result_of.hpp>

#if BOOST_ARCH_X86_32 && BOOST_COMP_MSVC

#define BOOST_RESULT_OF_S_CC __stdcall

namespace boost {

#if !defined(BOOST_NO_SFINAE) && !defined(BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
namespace detail {

template<typename R>
struct result_of_void_impl<R (BOOST_RESULT_OF_S_CC *)(void)>
{
    typedef R type;
};

template<typename R>
struct result_of_void_impl<R (BOOST_RESULT_OF_S_CC &)(void)>
{
    typedef R type;
};

} // end namespace detail

#define BOOST_PP_ITERATION_PARAMS_1 (3,(0,BOOST_RESULT_OF_NUM_ARGS,"detail/result_of_iterate_s.hpp"))
#include BOOST_PP_ITERATE()

#else // !defined(BOOST_NO_SFINAE) && !defined(BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
#  define BOOST_NO_RESULT_OF 1
#endif // !defined(BOOST_NO_SFINAE) && !defined(BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

}

#undef BOOST_RESULT_OF_S_CC

#define BOOST_RESULT_OF_S_CC __fastcall

namespace boost {

#if !defined(BOOST_NO_SFINAE) && !defined(BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
namespace detail {

template<typename R>
struct result_of_void_impl<R (BOOST_RESULT_OF_S_CC *)(void)>
{
    typedef R type;
};

template<typename R>
struct result_of_void_impl<R (BOOST_RESULT_OF_S_CC &)(void)>
{
    typedef R type;
};

} // end namespace detail

#define BOOST_PP_ITERATION_PARAMS_1 (3,(0,BOOST_RESULT_OF_NUM_ARGS,"detail/result_of_iterate_s.hpp"))
#include BOOST_PP_ITERATE()

#else // !defined(BOOST_NO_SFINAE) && !defined(BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
#  define BOOST_NO_RESULT_OF 1
#endif // !defined(BOOST_NO_SFINAE) && !defined(BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

}

#undef BOOST_RESULT_OF_S_CC

#endif // BOOST_ARCH_X86_32

#endif // BOOST_RESULT_OF_S_HPP
