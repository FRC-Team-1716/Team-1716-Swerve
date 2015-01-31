// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "SetWheelOffSets.h"

SetWheelOffSets::SetWheelOffSets() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	FLOffset = Robot::driveTrain->frontLeftPos->GetDistance()-2.5;
	FROffset = Robot::driveTrain->frontRightPos->GetDistance()-2.5;
	RLOffset = Robot::driveTrain->rearLeftPos->GetDistance()-2.5;
	RROffset = Robot::driveTrain->rearRightPos->GetDistance()-2.5;
	File = RAWCConstants::getInstance();
}

// Called just before this Command runs the first time
void SetWheelOffSets::Initialize() {
	File = RAWCConstants::getInstance();
	if(DriverStation::GetInstance()->IsDisabled()){
		FLOffset = Robot::driveTrain->frontLeftPos->GetDistance()-2.5;
		FROffset = Robot::driveTrain->frontRightPos->GetDistance()-2.5;
		RLOffset = Robot::driveTrain->rearLeftPos->GetDistance()-2.5;
		RROffset = Robot::driveTrain->rearRightPos->GetDistance()-2.5;

		File->insertKeyAndValue("FLOff", FLOffset);
		File->insertKeyAndValue("FROff", FROffset);
		File->insertKeyAndValue("RLOff", RLOffset);
		File->insertKeyAndValue("RROff", RROffset);

		File->save();

		Robot::driveTrain->SetOffsets(FLOffset, FROffset, RLOffset, RROffset);
	
		SetTimeout(2);
	}
	else
		SetTimeout(0);
}

// Called repeatedly when this Command is scheduled to run
void SetWheelOffSets::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool SetWheelOffSets::IsFinished() {
	//return false;
	return IsTimedOut();
}

// Called once after isFinished returns true
void SetWheelOffSets::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetWheelOffSets::Interrupted() {

}
