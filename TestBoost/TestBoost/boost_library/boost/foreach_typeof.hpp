/* Added by Hugo */
#ifndef BOOST_FOREACH_TYPEOF_HPP_INCLUDED
#define BOOST_FOREACH_TYPEOF_HPP_INCLUDED

#include <boost/typeof/typeof.hpp>
#include <boost/foreach.hpp>

#define BOOST_FOREACH_AUTO(VAR, COL)                                                                                   \
	BOOST_FOREACH_PREAMBLE()                                                                                      \
	if (boost::foreach_detail_::auto_any_t BOOST_FOREACH_ID(_foreach_col) = BOOST_FOREACH_CONTAIN(COL)) {} else   \
	if (boost::foreach_detail_::auto_any_t BOOST_FOREACH_ID(_foreach_cur) = BOOST_FOREACH_BEGIN(COL)) {} else     \
	if (boost::foreach_detail_::auto_any_t BOOST_FOREACH_ID(_foreach_end) = BOOST_FOREACH_END(COL)) {} else       \
	for (bool BOOST_FOREACH_ID(_foreach_continue) = true;                                                         \
	BOOST_FOREACH_ID(_foreach_continue) && !BOOST_FOREACH_DONE(COL);                                    \
	BOOST_FOREACH_ID(_foreach_continue) ? BOOST_FOREACH_NEXT(COL) : (void)0)                            \
	if  (boost::foreach_detail_::set_false(BOOST_FOREACH_ID(_foreach_continue))) {} else                      \
	for (BOOST_AUTO(VAR, BOOST_FOREACH_DEREF(COL)); !BOOST_FOREACH_ID(_foreach_continue); BOOST_FOREACH_ID(_foreach_continue) = true)

#define BOOST_REVERSE_FOREACH_AUTO(VAR, COL)                                                                           \
	BOOST_FOREACH_PREAMBLE()                                                                                      \
	if (boost::foreach_detail_::auto_any_t BOOST_FOREACH_ID(_foreach_col) = BOOST_FOREACH_CONTAIN(COL)) {} else   \
	if (boost::foreach_detail_::auto_any_t BOOST_FOREACH_ID(_foreach_cur) = BOOST_FOREACH_RBEGIN(COL)) {} else    \
	if (boost::foreach_detail_::auto_any_t BOOST_FOREACH_ID(_foreach_end) = BOOST_FOREACH_REND(COL)) {} else      \
	for (bool BOOST_FOREACH_ID(_foreach_continue) = true;                                                         \
	BOOST_FOREACH_ID(_foreach_continue) && !BOOST_FOREACH_RDONE(COL);                                   \
	BOOST_FOREACH_ID(_foreach_continue) ? BOOST_FOREACH_RNEXT(COL) : (void)0)                           \
	if  (boost::foreach_detail_::set_false(BOOST_FOREACH_ID(_foreach_continue))) {} else                      \
	for (BOOST_AUTO(VAR, BOOST_FOREACH_DEREF(COL)); !BOOST_FOREACH_ID(_foreach_continue); BOOST_FOREACH_ID(_foreach_continue) = true)

#endif // BOOST_FOREACH_TYPEOF_HPP_INCLUDED
