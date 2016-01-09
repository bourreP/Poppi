/*
 * Leg.h
 *
 *  Created on: 6 janv. 2016
 *      Author: Vincent
 */

#ifndef HEXAPODE_LEG_H_
#define HEXAPODE_LEG_H_

#include <math.h>

#include "Servo.h"

#include "../Math/Vector3.h"
#include "../Math/Trigo.h"


enum LegPosition {
	Idle,
	Start,
	End
};

class Leg {
public:
	Leg();
	virtual ~Leg();
	void initRelativePosition(Vector3 dist, float angle);
	Vector3 hexapodSpaceToLocalSpace(Vector3 pos);
	void setDirection(Vector3 dir);
	void stop();
	bool hasReachedGoal();
	Vector3 processIK(Vector3 pos);
	void goTo(Vector3 pos);
	void goTo(LegPosition pos);
private:
	//Servos
	Servo m_gamma;						//Servo entre le corps et le coxa
	Servo m_alpha;						//Servo entre le coxa et le femur
	Servo m_beta;						//Servo entre le tibia et le femur

	//Geometry
	const float m_tibiaLength;			//Distance entre le moteur trois et la pointe de la patte
	const float m_femurLength;			//Distance entre les moteurs deux et trois
	const float m_coxaLength;			//Distance entre les deux premiers moteurs
	float m_angleToHexapod;				//Diff�rence d'angle entre le rep�re de la patte et le rep�re de l'hexapode
    Vector3 m_distanceToHexapod;		//Distance entre l'origine du rep�re de la patte et l'origine du rep�re de l'hexapode

	//Kinematic
	float m_speed;						//Vitesse de d�placement
    Vector3 m_startPosition;			//Position au d�but du mouvement
    Vector3 m_endPosition;				//Position � la fin du mouvement
    Vector3 m_idlePosition;				//Position en Idle (patte en l'air)
    Vector3 m_goal;						//Position � atteindre par la pointe  de la patte
    Vector3 m_gotoDirCenterPosition;	//Le point situ� au centre du segment effectu� par la pointe de la patte lors du d�placement. start et end son position en fonction de ce point.
};

#endif /* HEXAPODE_LEG_H_ */
