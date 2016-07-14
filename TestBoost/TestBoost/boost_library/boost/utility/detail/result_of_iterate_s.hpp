// Boost result_of library

//  Copyright Douglas Gregor 2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

//  Copyright Daniel Walker, Eric Niebler, Michel Morin 2008-2012.
//  Use, modification and distribution is subject to the Boost Software
//  License, Version 1.0. (See accompanying file LICENSE_1_0.txt or
//  copy at http://www.boost.org/LICENSE_1_0.txt)

// For more information, see http://www.boost.org/libs/utility
#if !defined(BOOST_PP_IS_ITERATING)
# error Boost result_of - do not include this file!
#endif

// CWPro8 requires an argument in a function type specialization
#if BOOST_WORKAROUND(__MWERKS__, BOOST_TESTED_AT(0x3002)) && BOOST_PP_ITERATION() == 0
# define BOOST_RESULT_OF_ARGS void
#else
# define BOOST_RESULT_OF_ARGS BOOST_PP_ENUM_PARAMS(BOOST_PP_ITERATION(),T)
#endif

#undef BOOST_RESULT_OF_ARGS

#if BOOST_PP_ITERATION() >= 1

namespace detail {

template<typename R,  typename FArgs BOOST_PP_ENUM_TRAILING_PARAMS(BOOST_PP_ITERATION(),typename T)>
struct tr1_result_of_impl<R (BOOST_RESULT_OF_S_CC *)(BOOST_PP_ENUM_PARAMS(BOOST_PP_ITERATION(),T)), FArgs, false>
{
  typedef R type;
};

template<typename R,  typename FArgs BOOST_PP_ENUM_TRAILING_PARAMS(BOOST_PP_ITERATION(),typename T)>
struct tr1_result_of_impl<R (BOOST_RESULT_OF_S_CC &)(BOOST_PP_ENUM_PARAMS(BOOST_PP_ITERATION(),T)), FArgs, false>
{
  typedef R type;
};

#if !BOOST_WORKAROUND(__BORLANDC__, BOOST_TESTED_AT(0x551))
template<typename R, typename FArgs BOOST_PP_ENUM_TRAILING_PARAMS(BOOST_PP_ITERATION(),typename T)>
struct tr1_result_of_impl<R (BOOST_RESULT_OF_S_CC T0::*)
                     (BOOST_PP_ENUM_SHIFTED_PARAMS(BOOST_PP_ITERATION(),T)),
                 FArgs, false>
{
  typedef R type;
};

template<typename R, typename FArgs BOOST_PP_ENUM_TRAILING_PARAMS(BOOST_PP_ITERATION(),typename T)>
struct tr1_result_of_impl<R (BOOST_RESULT_OF_S_CC T0::*)
                     (BOOST_PP_ENUM_SHIFTED_PARAMS(BOOST_PP_ITERATION(),T))
                     const,
                 FArgs, false>
{
  typedef R type;
};

template<typename R, typename FArgs BOOST_PP_ENUM_TRAILING_PARAMS(BOOST_PP_ITERATION(),typename T)>
struct tr1_result_of_impl<R (BOOST_RESULT_OF_S_CC T0::*)
                     (BOOST_PP_ENUM_SHIFTED_PARAMS(BOOST_PP_ITERATION(),T))
                     volatile,
                 FArgs, false>
{
  typedef R type;
};

template<typename R, typename FArgs BOOST_PP_ENUM_TRAILING_PARAMS(BOOST_PP_ITERATION(),typename T)>
struct tr1_result_of_impl<R (BOOST_RESULT_OF_S_CC T0::*)
                     (BOOST_PP_ENUM_SHIFTED_PARAMS(BOOST_PP_ITERATION(),T))
                     const volatile,
                 FArgs, false>
{
  typedef R type;
};
#endif

}
#endif
