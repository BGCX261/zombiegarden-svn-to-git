#ifndef STATE_CLASS
#define STATE_CLASS

#include <string>

/**
 * \file State.hpp
 * \class State
 * \brief A state (true or false)
 * \author Vink
 *
 * A state (true or false)
 *
 */
class State{
	private :
		//! Name of the state
		std::string name;
		//! Value of the state
		bool state;

	public :
		//! Constructor
		//!\param name Name of the state
		//!\param state Value of the state (true or false)
		State(std::string name, bool state);

		//Getters and Setters
		//! Returns the value of the state
		bool getState(){return state;}
		//! Modify the value of the state
		void setState(bool value){state = value;}
};


#endif	// STATE_CLASS