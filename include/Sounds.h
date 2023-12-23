#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include <map>
#include "macros.h"

//singleton class
class Sounds {
public:
	~Sounds() = default;
	static Sounds& instance();
	void PlaySound(SoundsType soundName);
	void stopPlaying(bool all);
	void setMute(bool status);
	sf::SoundBuffer& getbuffer(SoundsType);

private:
	Sounds();
	Sounds(const Sounds&) = default;
	Sounds& operator=(const Sounds&) = default;
	std::map<SoundsType, sf::SoundBuffer> m_sounds;
	sf::Sound m_playingSound;
	SoundsType m_plyingNow;
	bool m_mute;
};