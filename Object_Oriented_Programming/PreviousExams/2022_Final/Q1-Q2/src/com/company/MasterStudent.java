package com.company;

public class MasterStudent extends Student implements ConferenceScoreBehaviour{
    protected int numberOfConf;

    public MasterStudent(int id, float mid, float fin, int numberOfConf) {
        super(id, mid, fin);
        this.numberOfConf = numberOfConf;
    }

    @Override
    float computeTotalScore() {
        return computeBaseScore() + conferenceScore();
    }

    @Override
    public float conferenceScore() {
        return numberOfConf * 5;
    }
}
