#include "Sounds.h"

Sounds::Sounds():m_sounds()
{
    m_sounds[SWIM ].loadFromFile("swi.wav");
	m_sounds[EAT ].loadFromFile("eat.wav" );
    m_sounds[EXPLODING ].loadFromFile("exp.wav");
    m_playingSound = sf::Sound();
    m_playingSound.setVolume(20);
    m_mute = false;
}//end constructor 

Sounds& Sounds::instance()
{//create static Sound object and return it
	static Sounds sound;
	return sound;
}//end instance 

void Sounds::PlaySound(SoundsType soundName)
{

    if (m_mute)
    {
        this->stopPlaying(true);
        return;
    }

    if (m_plyingNow != soundName || m_playingSound.getStatus() != sf::Sound::Playing)
    {
        m_playingSound.setBuffer(m_sounds[soundName]);
        m_playingSound.play();
        m_plyingNow = soundName;
    }
    

}//end PlaySound 

void Sounds::stopPlaying(bool all)
{
    if ((m_plyingNow != EAT && m_plyingNow != EXPLODING) || (all && m_plyingNow != EXPLODING))
      m_playingSound.stop();
}//end stopPlaying 

void Sounds::setMute(bool status)
{
    m_mute = status;
}
sf::SoundBuffer& Sounds::getbuffer(SoundsType current)
{
    return m_sounds[current];
}
//end setMute 

