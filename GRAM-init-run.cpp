


#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64) || defined(__WIN64__) || defined(WIN64)
	#define OS_WINDOWS
#endif

#if defined(OS_WINDOWS) && defined(_USRDLL)
	#undef DLL
	#define DLL __declspec(dllimport)
#endif



#if defined(OS_WINDOWS) && defined(_USRDLL)
	#undef DLL
	#define DLL __declspec(dllexport)
#endif

#include <stdio.h>      /* printf */
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>//
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>

#include "..\\EarthGRAM2016Version2\\EarthGRAM2016Version2.0\\Source\\Atmod.h"
#include "..\\EarthGRAM2016Version2\\EarthGRAM2016Version2.0\\Source\\Var.h"

#ifdef __cplusplus
extern "C" {
#endif


void init_arr(std::vector<double>* temp_arr,double x_0,double x_delta, int num){
   
   if (temp_arr->size()>=1){
        temp_arr->clear();
    }

    for(int i=0; i<num; i++){
        temp_arr->push_back(x_0+x_delta*i);
    }

};

class Atm_ : public  Atm{
    public:
    void initdata(){	//The member function initdata, of the Atmod Class, that initializes the data
                    //needed to compute the atmospheric variables for output.

                    string NCEPp, RRAp;

                    //Output statement displayed when program is executed.
                    cout << "Earth-GRAM 2016" << '\n';
                    set_member_data();
                    //Set the variables for number seed (nr1) and month (mn) from the namelist file.
                    nr1 = msisa1.maps.perts.iperts.inits1.nr1;
                    mn = msisa1.maps.perts.iperts.inits1.mn;

                    //Output statement when GRAM initialization begins.
                    cout << "GRAM Initialization" << '\n';

                    //Call the init1 member function from the Init class to initialize the
                    //atmosdat data into arrays.
                    msisa1.maps.perts.iperts.inits1.init1(mn);

                    //Initialize NCEP data
                    NCEPp = msisa1.maps.perts.iperts.inits1.NCEPpath;
                    msisa1.maps.perts.iperts.ncps.init(NCEPp);
                    msisa1.maps.perts.iperts.ncps.NCEPread();

                    //Initialize Auxiliary Profile data
                    if (msisa1.maps.perts.iperts.inits1.iaux > 0){
                        msisa1.maps.perts.iperts.auxs.rdprof(msisa1.maps.perts.iperts.inits1.sitenear,
                            msisa1.maps.perts.iperts.inits1.sitelim, msisa1.maps.perts.iperts.inits1.home,
                            msisa1.maps.perts.iperts.inits1.profile);
                    }
                    //Initialize RRA data
                    RRAp = msisa1.maps.perts.iperts.inits1.rrapath;
                    msisa1.maps.perts.iperts.rras.init(RRAp);
    };

     void set_member_data(){
        		//namelist member function from Init class
		//Open and read namelist input file for setting model parameters.

		double iday1[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		ifstream namelist;
		string dummy, NCEPmn;
		string mn1 = "12";
		NCEPmn = "Nb9008" + mn1 + ".bin";

		msisa1.maps.perts.iperts.inits1.rralist = "rrasites.txt";
		msisa1.maps.perts.iperts.inits1.profile = "RRAanfAnn.txt";
		msisa1.maps.perts.iperts.inits1.h1 = 140;
		msisa1.maps.perts.iperts.inits1.phi1 = 0.45;
		msisa1.maps.perts.iperts.inits1.thet1 = -164.53;
		//msisa1.maps.perts.iperts.inits1.f10 = 230;
		//msisa1.maps.perts.iperts.inits1.f10b  = 230;
		//msisa1.maps.perts.iperts.inits1.ap = 16.3;
		//msisa1.maps.perts.iperts.inits1.s10 = 0;
		//msisa1.maps.perts.iperts.inits1.s10b = 0;
		//msisa1.maps.perts.iperts.inits1.xm10 = 0;
		//msisa1.maps.perts.iperts.inits1.xm10b = 0;
		//msisa1.maps.perts.iperts.inits1.y10 = 0;
		//msisa1.maps.perts.iperts.inits1.y10b = 0;
		//msisa1.maps.perts.iperts.inits1.dstdtc = 0;
		//msisa1.maps.perts.iperts.inits1.mn = 1;
		//msisa1.maps.perts.iperts.inits1.ida = 1;
		//msisa1.maps.perts.iperts.inits1.iyr = 2018;
		//msisa1.maps.perts.iperts.inits1.ihro = 0;
		//msisa1.maps.perts.iperts.inits1.mino = 0;
		//msisa1.maps.perts.iperts.inits1.seco = 0.0;
		msisa1.maps.perts.iperts.inits1.dphi = 0.4;
		msisa1.maps.perts.iperts.inits1.dthet = 1.2;
		msisa1.maps.perts.iperts.inits1.dhgt = -2.0;
		msisa1.maps.perts.iperts.inits1.nmax = 71;
		msisa1.maps.perts.iperts.inits1.delt = 60.0;
		msisa1.maps.perts.iperts.inits1.iopt = 0;
		msisa1.maps.perts.iperts.inits1.iaux = 0;
		msisa1.maps.perts.iperts.inits1.iprt = 1;
		msisa1.maps.perts.iperts.inits1.inpr = 1;
		msisa1.maps.perts.iperts.inits1.icon = 1;
		msisa1.maps.perts.iperts.inits1.NCEPyr = 9715;
		msisa1.maps.perts.iperts.inits1.NCEPhr = 5;
		msisa1.maps.perts.iperts.inits1.mc = 2;
		//msisa1.maps.perts.iperts.inits1.rpscale = 1.0;
		//msisa1.maps.perts.iperts.inits1.ruscale = 1.0; 
		//msisa1.maps.perts.iperts.inits1.rwscale = 1.0;
		msisa1.maps.perts.iperts.inits1.iurra = 1;
		msisa1.maps.perts.iperts.inits1.iyrra = 3;
		msisa1.maps.perts.iperts.inits1.sitelim = 2.5;
		msisa1.maps.perts.iperts.inits1.sitenear = 0.5;
		msisa1.maps.perts.iperts.inits1.initpert = 0;
		msisa1.maps.perts.iperts.inits1.rdinit = 0.0;
		msisa1.maps.perts.iperts.inits1.rtinit = 0.0;
		msisa1.maps.perts.iperts.inits1.ruinit = 0.0;
		msisa1.maps.perts.iperts.inits1.rvinit = 0.0;
		msisa1.maps.perts.iperts.inits1.rwinit = 0.0;
		msisa1.maps.perts.iperts.inits1.patchy = 0.0;
		msisa1.maps.perts.iperts.inits1.itherm = 1;
		//msisa1.maps.perts.iperts.inits1.z0in = -1;
		msisa1.maps.perts.iperts.inits1.ibltest = 99;

		//start added by victor
		 msisa1.maps.perts.iperts.inits1.ibltest=1;
		//end added by victor

		//Check bounds on z0in value
		if (msisa1.maps.perts.iperts.inits1.z0in > 0.0){
			if (msisa1.maps.perts.iperts.inits1.z0in < 1.0e-05) msisa1.maps.perts.iperts.inits1.z0in = 1.0e-05;
			if (msisa1.maps.perts.iperts.inits1.z0in > 3.0) msisa1.maps.perts.iperts.inits1.z0in = 3.0;
		}

		//Check sitelim and sitenear
		if (msisa1.maps.perts.iperts.inits1.sitelim <= 0.0 || msisa1.maps.perts.iperts.inits1.sitenear >= msisa1.maps.perts.iperts.inits1.sitelim){
			cout << "Bad RRA site limits (sitenear must be < sitelim)  " << msisa1.maps.perts.iperts.inits1.sitenear <<
				"  " << msisa1.maps.perts.iperts.inits1.sitelim << '\n';
			system("pause");
			exit(1);
		}

		//Terminate if month out of range
		if (msisa1.maps.perts.iperts.inits1.mn < 1 || msisa1.maps.perts.iperts.inits1.mn > 12){
			cout << "Month out of range.  " << mn << '\n';
			system("pause");
			exit(1);
		}

		//Terminate if day out of range
		if ((msisa1.maps.perts.iperts.inits1.ida > iday1[msisa1.maps.perts.iperts.inits1.mn - 1]) || (msisa1.maps.perts.iperts.inits1.ida < 0)){
			cout << "Bad day input.  " << msisa1.maps.perts.iperts.inits1.ida << '\n';
			system("pause");
			exit(1);
		}

		//Terminate initial hour if out of range
		if ((msisa1.maps.perts.iperts.inits1.ihro > 23) || (msisa1.maps.perts.iperts.inits1.ihro < 0)){
			cout << "Bad hour input.  " << msisa1.maps.perts.iperts.inits1.ihro << '\n';
			system("pause");
			exit(1);
		}

		//Terminate if initial minute out of range
		if ((msisa1.maps.perts.iperts.inits1.mino > 60) || (msisa1.maps.perts.iperts.inits1.mino < 0)){
			cout << "Bad minute input.  " << msisa1.maps.perts.iperts.inits1.mino << '\n';
			system("pause");
			exit(1);
		}

		//Terminate if initial second out of range
		if ((msisa1.maps.perts.iperts.inits1.seco > 60.0) || (msisa1.maps.perts.iperts.inits1.seco < 0.0)){
			cout << "Bad second input.  " << msisa1.maps.perts.iperts.inits1.seco << '\n';
			system("pause");
			exit(1);
		}

		//Terminate if out of range NCEPhr
		if (msisa1.maps.perts.iperts.inits1.NCEPhr < 0 || msisa1.maps.perts.iperts.inits1.NCEPhr > 5){
			cout << "Bad NCEPhr value." << '\n';
			system("pause");
			exit(1);
		}
		//Terminate if auxiliary profile and RRA data turned on
		if (msisa1.maps.perts.iperts.inits1.iaux > 0 && msisa1.maps.perts.iperts.inits1.iurra > 0){
			cout << "Can not use RRA data and auxiliary profile data simultaneously."
				<< '\n';
			system("pause");
			exit(1);
		}

		if (msisa1.maps.perts.iperts.inits1.itherm == 1) msisa1.maps.perts.iperts.inits1.therm = "MET";
		if (msisa1.maps.perts.iperts.inits1.itherm == 2) msisa1.maps.perts.iperts.inits1.therm = "MSIS";
		if (msisa1.maps.perts.iperts.inits1.itherm == 3) msisa1.maps.perts.iperts.inits1.therm = "JB2008";

		if (msisa1.maps.perts.iperts.inits1.patchy > 0) msisa1.maps.perts.iperts.inits1.patch = "On";
		if (msisa1.maps.perts.iperts.inits1.patchy == 0) msisa1.maps.perts.iperts.inits1.patch = "Off";

		if (msisa1.maps.perts.iperts.inits1.iyrra == 1) msisa1.maps.perts.iperts.inits1.Ryear = "1983";
		if (msisa1.maps.perts.iperts.inits1.iyrra == 2) msisa1.maps.perts.iperts.inits1.Ryear = "2006";
		if (msisa1.maps.perts.iperts.inits1.iyrra == 3) msisa1.maps.perts.iperts.inits1.Ryear = "2013";

		h1a = h1;
		phi1a = phi1;
		thet1a = thet1;
		
		f101 = msisa1.maps.perts.iperts.inits1.f10;
		f10b1 = msisa1.maps.perts.iperts.inits1.f10b;
		ap1 = msisa1.maps.perts.iperts.inits1.ap;
		s101 = msisa1.maps.perts.iperts.inits1.s10;
		s10b1 = msisa1.maps.perts.iperts.inits1.s10b;
		xm101 = msisa1.maps.perts.iperts.inits1.xm10;
		xm10b1 = msisa1.maps.perts.iperts.inits1.xm10b;
		y101 = msisa1.maps.perts.iperts.inits1.y10;
		y10b1 = msisa1.maps.perts.iperts.inits1.y10b;
		dstdtc1 = msisa1.maps.perts.iperts.inits1.dstdtc;
		mn2 = msisa1.maps.perts.iperts.inits1.mn;
		ida1 = msisa1.maps.perts.iperts.inits1.ida;
		iyr1 = msisa1.maps.perts.iperts.inits1.iyr;
		ihro1 = msisa1.maps.perts.iperts.inits1.ihro;
		mino1 = msisa1.maps.perts.iperts.inits1.mino;
		seco1 = msisa1.maps.perts.iperts.inits1.seco;
		dphi1 = msisa1.maps.perts.iperts.inits1.dphi;
		dthet1 = msisa1.maps.perts.iperts.inits1.dthet;
		dhgt2 = msisa1.maps.perts.iperts.inits1.dhgt;
		nmax1 = msisa1.maps.perts.iperts.inits1.nmax;
		delt1 = msisa1.maps.perts.iperts.inits1.delt;
		iopt1 = msisa1.maps.perts.iperts.inits1.iopt;
		iaux1 = msisa1.maps.perts.iperts.inits1.iaux;
		iprt1 = msisa1.maps.perts.iperts.inits1.iprt;
		inpr1 = msisa1.maps.perts.iperts.inits1.inpr;
		icon1 = msisa1.maps.perts.iperts.inits1.icon;
		NCEPyr3 = msisa1.maps.perts.iperts.inits1.NCEPyr;
		NCEPhr3 = msisa1.maps.perts.iperts.inits1.NCEPhr;
		mc1 = msisa1.maps.perts.iperts.inits1.mc;
		rpscale1 = msisa1.maps.perts.iperts.inits1.rpscale;
		ruscale1 = msisa1.maps.perts.iperts.inits1.ruscale;
		rwscale1 = msisa1.maps.perts.iperts.inits1.rwscale;
		iurra1 = msisa1.maps.perts.iperts.inits1.iurra;
		iyrra1 = msisa1.maps.perts.iperts.inits1.iyrra;
		sitelim1 = msisa1.maps.perts.iperts.inits1.sitelim;
		sitenear1 = msisa1.maps.perts.iperts.inits1.sitenear;
		initpert1 = msisa1.maps.perts.iperts.inits1.initpert;
		rdinit1 = msisa1.maps.perts.iperts.inits1.rdinit;
		rtinit1 = msisa1.maps.perts.iperts.inits1.rtinit;
		ruinit1 = msisa1.maps.perts.iperts.inits1.ruinit;
		rvinit1 = msisa1.maps.perts.iperts.inits1.rvinit;
		rwinit1 = msisa1.maps.perts.iperts.inits1.rwinit;
		patchy1 = msisa1.maps.perts.iperts.inits1.patchy;
		itherm1 = msisa1.maps.perts.iperts.inits1.itherm;
		z0in1 = msisa1.maps.perts.iperts.inits1.z0in;
		ibltest1 = msisa1.maps.perts.iperts.inits1.ibltest;
		nr1a = msisa1.maps.perts.iperts.inits1.nr1;
	}

        
    void traj2(double hgt, double lat, double lon, double time, int iupdate, int initonce, double *dmout,
	double *pmout, double *tmout, double *umout, double *vmout, double *wmout, double *dpout, double *ppout,
	double *tpout, double *upout, double *vpout, double *wpout, double *dsout, double *psout,
	double *tsout, double *usout, double *vsout, double *wsout, double *dsmall, double *psmall,
	double *tsmall, double *usmall, double *vsmall, double *wsmall, double *sosmean, double *sospert){	//traj member function for the atmod class
            //Main member function to calculate mean and standard deviation of pressure,
            //density, temperature, and winds.  As well as perturbed values and atmospheric
            //constituents.  This member function allows the capability to plug-in to simulation.
            
            using namespace std;

            double pgh, tgh, dgh, ugh, vgh, hg1 = 0.0, hg2 = 0.0;
            double g0 = 0.0, g = 0.0, re = 0.0, r0 = 0.0, ri1 = 0.0, phir = 0.0, ri = 0.0;
            double czi, pmm, dmm, tmm, umm, vmm, wmm, water, dest,
                rhrra, shrra, sigest, srhf, corr, srhrra, tdsrf,
                stdsrf, totppm, ppmscale, totnd, dphi0 = 0.0, FS, spdgh, sdsph, su, sv,
                sp = 0.0, st = 0.0, sd = 0.0, sw = 0.0, swg = 0.0, spj, stj, sdj, suj, svj, swj;
            double r0a = 287.055, onemeg = 1.0e+06, gasconst, cpmn, csp0, csp, mwnd, t1, p1, d1;
            
            double pghp, dghp, tghp, php, dhp, thp, onec = 100.0, prhp, drhp, trhp, prsp, drsp,
                trsp, prlp, drlp, trlp, spsp, sdsp, stsp, splp, sdlp, stlp, sphp, sdhp, sthp;
            double gdlat, req = 6378.137, rpo = 6356.752314, gdhgt, ffac;
            string rra_id;
            string nprp = msisa1.maps.perts.iperts.inits1.home + msisa1.maps.perts.iperts.inits1.nprpath;
            string conp = msisa1.maps.perts.iperts.inits1.home + msisa1.maps.perts.iperts.inits1.conpath;
            double rrawt = 0.0, grmwt = 0.0, rrawts, grmwts, hgtp, hgtd, splim;
            double h2 = 0.0, phi2 = 0.0, thet2 = 0.0, time2 = 0.0;
            int f1 = 0, i, ihr = msisa1.maps.perts.iperts.inits1.ihro;
            phir = phi * pi180;
            iupdate1 = iupdate;
            //nr1 = nr1a;

            if (initonce > 0){

                //File open for the "special.txt" and "species.txt" output files.
/*
                if (inpr1 > 0){
                    output.open(nprp.c_str());
                }
                if (icon1 > 0){
                    species.open(conp.c_str());
                }
*/
 /*
                //Headers for the "species.txt" and "special.txt" output files.
                species << "   Height   GcLat    Long.     Conc.     #Dens.   |    Conc.     #Dens.     Species" << '\n';
                species << "    (km)    (deg)    (deg)    (ppmv)    (#/m^3)   |    (ppmv)   (#/m^3)" << '\n';
                output << "      Time    Hgtkm GeocenLat  Lon(East)   DensMean   PresMean    Tmean "
                    "  EWmean"
                    "   NSmean   DensPert   PresPert    Tpert   EWpert  NSpert SDden% SDprs% "
                    "SDtemK SDuwnd SDvwnd SDwwnd Wpert SpdAvg  SpdStd SOSmean SOSpert Sev" << '\n';


                msisa1.maps.perts.iperts.inits1.out << "  Height/  GcLat    Long.                        Tempera-               Vert." << '\n' <<
                    "  Radius   GdLat   [E+W-]  Pressure   Density/     ture/   E-W    N-S   Wind" << '\n' <<
                    "   (km)    (deg)    (deg)  /Vap.Pr.   Vap.Dens.    Dewpt.  Wind   Wind  (m/s)" <<
                    '\n' << "  Time_sec  /RRA   /Weight (Nt/m**2)  (kg/m**3)    (K)    (m/s)  (m/s)  RH(%)" << '\n' <<
                    " --------- ------ -------  ----------  ---------- ------  ------ ------ ----- ----" << '\n';
*/

                h = hgt;
                phi = lat;
                thet = lon;
                elt = time;
                timec = time;

                msisa1.maps.perts.elt = elt;

                



                i = 0;
                nm = 0;


                //Interpret input height as radius if h > 6000
                if (h > 6000.0){
                    //Get local Earth radius r0
                    phir = phi*pi180;
                    msisa1.maps.perts.rig(0.0, phir, &g0, &g, &re, &r0, &ri);
                    h = h - r0;
                }

                //Terminate if height < -30 m below sea level
                if (h < (-0.031)){
                    cout << "Height below -30m sea level, h = " << h << '\n';
                    system("pause");
                    exit(1);

                }

                //Output seed value if mc > 1
                if (msisa1.maps.perts.iperts.inits1.mc > 1){
                    cout << "Seed value for Monte Carlo:  " << nr1 << '\n';
                }



                spdavg = 0.0;

                //Adjust phi, thet if trajectory cross the pole.
                if (abs(phi) > 90.0){
                    phi = copysign(180.0 - abs(phi), phi);
                    thet = thet + 180.0;
                    if (thet >= 180.0) thet = thet - 360.0;
                }
                if (thet < (-180.0)) thet = thet + 360.0;
                
                //Calculate the initial perturbations at initial state.
                initpert();

                //Call pert member function to calculate xlh and zlh for next perturbed value. 
                pert();

                //Increment first number seed (nr1) for Monte Carlo runs
                
                //Call member function initsigs from Pert class to save the initial standard
                //deviations needed for calculating perturbation.
                msisa1.maps.perts.initsigs();


                //If h < 40.0 call the gethgs member function from the NCEP class to get
                //the height at the 10 mb (hg2) and 20 mb (hg1) level
                if (h < 40.0){
                    msisa1.maps.perts.iperts.ncps.gethgs(phi, thet, &hg1, &hg2);
                }


                //If height <= height of 10 mb level use NCEP data 
                if (h <= hg2){

                    //Compute NCEP data values by calling ncep member function
                    ncep();
                    dtz1 = msisa1.maps.perts.iperts.ncps.dtz;
                    //Get mean and sigma water vapor volume mixing ratio for NCEP
                    waterg = onemeg*vpn / (pnmean - vpn);
                    sigwater = waterg*svpn / vpn;

                    //Use only NCEP values if below height hg1
                    if (h < hg1){
                        pmean = pnmean;
                        dmean = dnmean;
                        tmean = tnmean;
                        umean = unmean;
                        vmean = vnmean;
                        wmean = wnmean;
                    }
                    else {
                        //Fair between NCEP and middle-atmosphere values if height
                        //between hg1 and hg2

                        //Call map member function for calculating values from MAP data
                        map();

                        //Call intruv member function from InitP class to calculate standard
                        //deviation of winds from MAP data.  Used to calculate spdavg and 
                        //spdsd.
                        msisa1.maps.perts.iperts.intruv(ur,
                            vr, h, phi, &su, &sv);
                        su = sqrt(abs(su));
                        sv = sqrt(abs(sv));

                        //call fair member function to fair between NCEP and MAP
                        fair(1, hg1, pnmean, dnmean, tnmean, unmean, vnmean, wnmean, hg2,
                            pmean1, dmean1, tmean1, umean1, vmean1, wmean1, h, &pmm,
                            &dmm, &tmm, &umm, &vmm, &wmm, &czi);
                        fair(2, hg1, spg, sdg, stg, sug, svg, swg, hg2, sp, sd, st, su, sv,
                            sw, h, &spj, &sdj, &stj, &suj, &svj, &swj, &czi);
                        pmean = pmm;
                        dmean = dmm;
                        tmean = tmm;
                        umean = umm;
                        vmean = vmm;
                        wmean = wmm;

                        if ((tmean1 - tnmean) != 0.0){
                            ffac = (tmean - tnmean) / (tmean1 - tnmean);
                            dtz1 = msisa1.maps.perts.iperts.ncps.dtz + ffac*(dtzm -
                                msisa1.maps.perts.iperts.ncps.dtz);
                        }

                        //Apply ruscale to standard deviation of u and v wind components.
                        suj = ruscale1*suj;
                        svj = ruscale1*svj;

                        //Calculate a faired value for wind speed and wind speed standard deviation.
                        FS = pow(suj, 2.0) + pow(svj, 2.0);
                        spdavg = czi*spdavg + (1.0 - czi)*sqrt(pow(umean, 2.0) + pow(vmean, 2.0) + 0.605*FS);
                        spdsd = czi*spdsd + (1.0 - czi)*sqrt(0.395*FS);
                    }

                }
                //Use MET, MSIS, or JB2008 thermosphere model if height above hj1, 90 km.
                else if (h >= hj1){

                    //Call thermosphere model based on user-selected input 'itherm'.
                    if (itherm1 == 1){
                        met();
                        dtz1 = msisa1.maps.perts.iperts.mets.dtz;
                        dmdz1 = msisa1.maps.perts.iperts.mets.dmdz;
                    }
                    else if (itherm1 == 2){
                        msis();
                        dtz1 = msisa1.dtz;
                    }
                    else if (itherm1 == 3){
                        jb2008();
                        dtz1 = msisa1.jb2008.dtz;
                    }


                    //Use only thermosphere model data if height above hj2, 120 km.
                    if (h >= hj2){
                        pmean = pmean2;
                        dmean = dmean2;
                        tmean = tmean2;
                        umean = umean2;
                        vmean = vmean2;
                        wmean = wmean2;
                        Umean = umean2;
                        Vmean = vmean2;
                    }
                    else {
                        //Fair between thermosphere and middle-atmosphere values
                        //if height between hj1 and hj2.
                        map();
                        fair(1, hj1, pmean1, dmean1, tmean1, umean1, vmean1, wmean1, hj2,
                            pmean2, dmean2, tmean2, umean2, vmean2, wmean2, h, &pmm, &dmm,
                            &tmm, &umm, &vmm, &wmm, &czi);

                        pmean = pmm;
                        dmean = dmm;
                        tmean = tmm;
                        umean = umm;
                        vmean = vmm;
                        wmean = wmm;
                        Umean = umm;
                        Vmean = vmm;

                        if ((tmean1 - tmean2) != 0.0){
                            ffac = (tmean - tmean2) / (tmean1 - tmean2);
                            dtz1 = dtz1 + ffac*(dtzm - dtz1);
                        }

                    }
                }
                else {
                    //Use only middle-atmosphere values if height between hg2 and 
                    //hj1.
                    map();
                    pmean = pmean1;
                    dmean = dmean1;
                    tmean = tmean1;
                    umean = umean1;
                    vmean = vmean1;
                    wmean = wmean1;
                    Umean = umean;
                    Vmean = vmean;
                    dtz1 = dtzm;
                }

                //Call speconc member function to calculate species concentration data.
                speconc();

                //Use RRA data if height <= 70.0 and user-selected input variable iurra > 0.
                
                if ((h <= 70.0) & (iurra1 > 0)){

                    phir = phi*pi180;
                    msisa1.maps.perts.rig(h, phir, &g0, &g, &re, &r0, &ri1);

                    pgh = pmean;
                    dgh = dmean;
                    tgh = tmean;
                    ugh = umean;
                    vgh = vmean;
                    //Call rramean memeber function from RRA class to calculate RRA mean data.
                    msisa1.maps.perts.iperts.rras.rramean(h, phi, thet, mn, r0, &pgh,
                        &dgh, &tgh, &ugh, &vgh, rra_id, &rrawt);

                    if (msisa1.maps.perts.iperts.rras.z1[msisa1.maps.perts.iperts.rras.num1 - 1]){
                        urramean = ugh;
                        vrramean = vgh;
                    }

                    if (msisa1.maps.perts.iperts.rras.z2[msisa1.maps.perts.iperts.rras.num2 - 1]){
                        prramean = pgh;
                        drramean = dgh;
                        trramean = tgh;
                    }

                    //Revise GRAM vapor pressure, dew point, RH, mixing ratio
                    //and standard deviations by weighted average with RRA data
                    int num3a = msisa1.maps.perts.iperts.rras.num3;

                    if (h <= msisa1.maps.perts.iperts.rras.z3[num3a - 1]){
                        grmwt = 1.0 - msisa1.maps.perts.iperts.rras.rrawt3;
                        eoft = rrawt*msisa1.maps.perts.iperts.rras.vprra + grmwt*eoft;
                        seoft = rrawt*msisa1.maps.perts.iperts.rras.svprra + grmwt*seoft;
                        tdmean = rrawt*msisa1.maps.perts.iperts.rras.tdrra + grmwt*tdmean;
                        stdd = rrawt*msisa1.maps.perts.iperts.rras.stdrra + grmwt*stdd;
                        water = 1.0e+06*eoft / (pmean - eoft);

                        dest = 0.5*msisa1.maps.d2edt2(msisa1.maps.perts.iperts.rras.trra,
                            msisa1.maps.perts.iperts.rras.prra)*msisa1.maps.perts.iperts.rras.strra;
                        rhrra = 100.0*msisa1.maps.perts.iperts.rras.vprra / (msisa1.maps.wexler(msisa1.maps.perts.iperts.rras.trra,
                            msisa1.maps.perts.iperts.rras.prra) + dest);
                        rhrra = max(3.0, rhrra);
                        rhrra = min(100.0, rhrra);

                        rhp = rrawt*rhrra + grmwt*rhp;
                        rhov = eps*eoft / (r0a*tmean);

                        if (eoft <= 0.0){
                            sigwater = 0.0;
                            shrra = 0.0;
                            srhov = 0.0;
                        }
                        else{
                            sigwater = water*seoft / eoft;
                            sigest = msisa1.maps.dedt(tmean, pmean)*tstd1*tmean / eoft;
                            srhov = rhov*sqrt(pow((seoft / eoft), 2.0) +
                                pow((stdd / tdmean), 2.0));
                            srhf = 1.43 + 0.315*log10(msisa1.maps.perts.iperts.rras.prra / 1.0e+05);
                            corr = 0.85 - 0.7*pow(cos(pi180*phi), 6.0);
                            srhrra = rhrra*sqrt(pow((seoft / eoft), 2.0) + pow(sigest, 2.0) -
                                2.0*corr*sigest*seoft / eoft) / srhf;
                            srhrra = min(50.0, srhrra);
                            srhrra = min(1.05*rhrra, srhrra);
                            srhrra = max(0.05*rhrra, srhrra);
                            srhp = rrawt*srhrra + grmwt*srhp;
                        }


                        ppmh2o = water;
                        h2ond = water*ppmtond;

                    }
                    //If height <= 27.0, calcuate a weighted RRA surface dewpoint mean and
                    //standard deviation.
                    if (h <= 27.0){
                        tdsrf = grmwt*tdmean + rrawt*msisa1.maps.perts.iperts.rras.tdsrf;
                        stdsrf = grmwt*stdd + rrawt*msisa1.maps.perts.iperts.rras.stdsrf;
                    }

                    double ztop, ztopm;
                    ztop = ztop1;
                    ztopm = ztop - 5.0;

                    double wdum = 0.0, wdum1, prg, drg, trg, urg, vrg, cz1, del, del1, del2;
                    if (h >= ztopm && h <= ztop && iyrra1 == 3){

                        del = urramean - urramean1;
                        del1 = vrramean - vrramean1;
                        del2 = trramean - trramean1;

            

                        //RRA Fair
                        fair(1, ztopm, prramean, drramean, trramean, urramean, vrramean, wdum,
                            ztop, pmean, dmean, tmean, umean, vmean, wdum, h, &prg, &drg, &trg,
                            &urg, &vrg, &wdum1, &cz1);

                        pmean = prg;
                        dmean = drg;
                        tmean = trg;
                        umean = urg;
                        vmean = vrg;

                    }

                    else {

                        pmean = prramean;
                        dmean = drramean;
                        tmean = trramean;
                        umean = urramean;
                        vmean = vrramean;

                    }

                    if (rrawt == 0) {
                        pmean = pgh;
                        dmean = dgh;
                        tmean = tgh;
                        umean = ugh;
                        vmean = vgh;
                    }

                }


                //Rescale non-water-vapor concentrations to correct for the effects of 
                //interpolation, fairing, and water vapor.
                totppm = ppmo3 + ppmn2o + ppmco + ppmch4 + ppmco2 + ppmn2 + ppmo2 +
                    ppmo + ppmar + ppmhe + ppmh + ppmn;

                ppmscale = (1.0e+06 - ppmh2o) / totppm;

                ppmo3 = ppmo3*ppmscale;
                ppmn2o = ppmn2o*ppmscale;
                ppmco = ppmco*ppmscale;
                ppmch4 = ppmch4*ppmscale;
                ppmco2 = ppmco2*ppmscale;
                ppmn2 = ppmn2*ppmscale;
                ppmo2 = ppmo2*ppmscale;
                ppmo = ppmo*ppmscale;
                ppmar = ppmar*ppmscale;
                ppmhe = ppmhe*ppmscale;
                ppmh = ppmh*ppmscale;
                ppmn = ppmn*ppmscale;
                ppmtond = avn*pmean / (8314.472e+6*tmean);
                h2ond = ppmh2o*ppmtond;
                o3nd = ppmo3*ppmtond;
                n2ond = ppmn2o*ppmtond;
                cond = ppmco*ppmtond;
                ch4nd = ppmch4*ppmtond;
                co2nd = ppmco2*ppmtond;
                n2nd = ppmn2*ppmtond;
                o2nd = ppmo2*ppmtond;
                ond = ppmo*ppmtond;
                arnd = ppmar*ppmtond;
                hend = ppmhe*ppmtond;
                hnd = ppmh*ppmtond;
                nnd = ppmn*ppmtond;
                totnd = h2ond + o3nd + n2ond + cond + ch4nd + co2nd + n2nd + o2nd + ond
                    + arnd + hend + hnd + nnd;
                mwnd = (h2ond*wth2o + o3nd*wto3 + n2ond*wtn2o + cond*wtco + ch4nd*wtch4 +
                    co2nd*wtco2 + n2nd*wtn2 + o2nd*wto2 + ond*wto + arnd*wtar + hend*wthe +
                    hnd*wth + nnd*wtn) / totnd;


                //Variables needed for using auxiliary profile data.
                double profout, tout, pout, dout, uout, vout,
                    sitenear = sitenear1,
                    sitelim = sitelim1;
                string home1 = msisa1.maps.perts.iperts.inits1.home;
                string profile1 = msisa1.maps.perts.iperts.inits1.profile;

                //If user-selected variable iaux > 0 use available auxiliary profile data.
                if (iaux1 > 0){

                    //call rdprof and profterp member functions from the AuxProf Class to 
                    //read profile data calculate mean profile data.
                    //msisa.maps.perts.iperts.auxs.rdprof(sitenear, sitelim, home1, profile1);
                    msisa1.maps.perts.iperts.auxs.profterp(h, phi, thet, tmean, pmean, dmean, umean,
                        vmean, &tout, &pout, &dout, &uout, &vout, &profout);

                    pmean = pout;
                    dmean = dout;
                    tmean = tout;
                    vmean = vout;
                    umean = uout;
                    
                    
                }

                //Calculate total perturbed values added to mean data.
                pmpert = pmean * (1 + ppert1);
                dmpert = dmean * (1 + dpert1);
                tmpert = tmean * (1 + tpert1);
                umpert = umean + upert1;
                vmpert = vmean + vpert1;
                wmpert = wmean + wpert1;


                //Insure wind component magnitudes < 0.7 times sound speed
                splim = 0.7*sqrt(1.4*pmpert / dmpert);
                if (abs(umpert) > splim) umpert = copysign(splim, umpert);
                if (abs(vmpert) > splim) vmpert = copysign(splim, vmpert);

                //Calculate average wind speed and wind speed standard deviation.
                //Use wind speed data if it is available.
                if (spdavg > 0){
                    spdgh = spdavg;
                    sdsph = spdsd;
                }
                else{
                    //Calculate wind speed if data is not available.
                    msisa1.maps.perts.iperts.intruv(ur,
                        vr, h, phi, &su, &sv);
                    su = sqrt(abs(su))*ruscale1;
                    sv = sqrt(abs(sv))*ruscale1;
                    FS = pow(su, 2.0) + pow(sv, 2.0);
                    spdgh = sqrt(pow(Umean, 2.0) + pow(Vmean, 2.0) + 0.605*FS);
                    sdsph = sqrt(0.3950*FS);

                }
                //Weight RRA wind speed data when it is available.
                if (msisa1.maps.perts.iperts.rras.sitewgt > 0.0 && h <= msisa1.maps.perts.iperts.rras.z1[msisa1.maps.perts.iperts.rras.num1 - 1]){
                    rrawts = msisa1.maps.perts.iperts.rras.rrawt1;
                    grmwts = 1.0 - rrawts;
                    spdgh = rrawts*msisa1.maps.perts.iperts.rras.avspdrra + grmwts*spdgh;
                    sdsph = rrawts*msisa1.maps.perts.iperts.rras.sdspdrra + grmwts*sdsph;
                }


                if ((msisa1.maps.perts.iperts.inits1.iaux) && (profout > 0.0)){
                    FS = pow(ustd1, 2.0) + pow(vstd1, 2.0);
                    spdgh = (sqrt(pow(umean, 2.0) + pow(vmean, 2.0) + 0.605*FS)*profout) + spdavg*(1 - profout);
                    sdsph = (sqrt(0.3950*FS)*profout) + spdsd*(1 - profout);
                }

                //Gas constant and ratio of specific heats
                gasconst = pmean / (dmean*tmean);
                cpmn = (1.4 / 0.4)*gasconst;

                //Sound speed (m/s) from mean and perturbed temperature
                csp0 = sqrt(1.4*gasconst*tmean);
                csp = sqrt(1.4*gasconst*tmpert);

                //Pressure scale height (m), density scale height (m)
                msisa1.maps.perts.rig(h, phir, &g0, &g, &re, &r0, &ri);
                hgtp = pmean / (dmean*g);
                if (h <= hg2) dtz1 = dtz1 / 1000.0;
                if (h <= hj1) {
                    hgtd = hgtp / (1.0 + hgtp*dtz1 / tmean);
                }
                else {
                    hgtd = hgtp / (1.0 + hgtp*dtz1 / tmean - hgtp*dmdz1 / wtmol);
                }

                //Output species concentration data to "species.txt"
               /* species << fixed << setw(9) << setprecision(3) << h << setw(8) << setprecision(3) <<
                    phi << setw(9) << setprecision(3) << thet << scientific << setw(12) << setprecision(3) <<
                    ppmh2o << setw(11) << setprecision(3) << h2ond << " |" << setw(11) << setprecision(3) <<
                    ppmo3 << setw(11) << setprecision(3) << o3nd << "  H2O |  O3" <<
                    '\n';
                species << scientific << setw(38) << setprecision(3) << ppmn2o << setw(11) <<
                    setprecision(3) << n2ond << " |" << setw(11) << setprecision(3) << ppmco <<
                    setw(11) << setprecision(3) << cond << "  N2O |  CO" <<
                    '\n';
                species << scientific << setw(38) << setprecision(3) << ppmch4 << setw(11) <<
                    setprecision(3) << ch4nd << " |" << setw(11) << setprecision(3) << ppmco2 <<
                    setw(11) << setprecision(3) << co2nd << "  CH4 | CO2" <<
                    '\n';
                species << scientific << setw(38) << setprecision(3) << ppmn2 << setw(11) <<
                    setprecision(3) << n2nd << " |" << setw(11) << setprecision(3) << ppmo2 <<
                    setw(11) << setprecision(3) << o2nd << "   N2 |  O2" <<
                    '\n';
                species << scientific << setw(38) << setprecision(3) << ppmo << setw(11) <<
                    setprecision(3) << ond << " |" << setw(11) << setprecision(3) << ppmar <<
                    setw(11) << setprecision(3) << arnd << "    O |  Ar" <<
                    '\n';
                species << scientific << setw(38) << setprecision(3) << ppmhe << setw(11) <<
                    setprecision(3) << hend << " |" << setw(11) << setprecision(3) << ppmh <<
                    setw(11) << setprecision(3) << hnd << "   He |   H" <<
                    '\n';
                species << scientific << setw(38) << setprecision(3) << ppmn << setw(11) <<
                    setprecision(3) << nnd << " | " << "MW=" << fixed << setw(6) << setprecision(3) << mwnd <<
                    scientific << setw(12) << setprecision(3) << totnd << "    N | Tot" <<
                    '\n';

                species << " -------- ------- --------  ---------- ----------   ---------- ----------  ---- ---- " << '\n';

                //Output data to "Special.txt".
                output << fixed << setw(10) << setprecision(2) << elt << setw(9) << setprecision(3) <<
                    h << setw(10) << setprecision(5) << phi << setw(11) << setprecision(5) << thet <<
                    scientific << setw(12) << setprecision(4) << dmean << setw(12) << setprecision(4) <<
                    pmean << fixed << setw(8) << setprecision(2) << tmean << setw(8) << setprecision(2) << umean <<
                    setw(8) << setprecision(2) << vmean << scientific << setw(12) << setprecision(4) << dmpert <<
                    setw(12) << setprecision(4) << pmpert << fixed << setw(8) << setprecision(2) << tmpert <<
                    setw(8) << setprecision(2) << umpert << setw(8) << setprecision(2) << vmpert << setw(7) <<
                    setprecision(2) << dstd1 * 100 << setw(7) << setprecision(2) << pstd1 * 100 << setw(7) << setprecision(2) <<
                    tmean*tstd1 << setw(7) << setprecision(2) << ustd1 << setw(7) << setprecision(2) << vstd1 <<
                    setw(7) << setprecision(2) << wstd1 << setw(7) << setprecision(2) << wmpert << setw(7) << setprecision(2) <<
                    spdgh << setw(7) << setprecision(2) << sdsph << setw(8) << setprecision(2) <<
                    csp0 << setw(8) << setprecision(2) << csp << setw(4) << msisa1.maps.perts.isev <<
                    '\n';
*/
                //Process data for Output data to Output.txt

                //stdatm member function from Atmod Class to calculate standard atmosphere
                stdatm(h, &t1, &p1, &d1);

                //Calculate percent deviation of GRAM mean from stadard atmosphere
                if (p1*d1*t1 > 0){
                    pghp = onec*(pmean - p1) / p1;
                    dghp = onec*(dmean - d1) / d1;
                    tghp = onec*(tmean - t1) / t1;
                    php = onec*(pmpert - p1) / p1;
                    dhp = onec*(dmpert - d1) / d1;
                    thp = onec*(tmpert - t1) / t1;
                }
                else {
                    pghp = 0.0;
                    dghp = 0.0;
                    tghp = 0.0;
                    php = 0.0;
                    dhp = 0.0;
                    thp = 0.0;
                }




                //Converts random p,d,t and standard deviations to percent
                prhp = onec*prh1a;
                drhp = onec*drh1a;
                trhp = onec*trh1a;
                prsp = onec*rp1sa;
                drsp = onec*rd1sa;
                trsp = onec*rt1sa;
                prlp = onec*rp1la;
                drlp = onec*rd1la;
                trlp = onec*rt1la;
                sphp = onec*sp1;
                sdhp = onec*sd1;
                sthp = onec*st1;
                spsp = onec*sp1sa;
                sdsp = onec*sd1sa;
                stsp = onec*st1sa;
                splp = onec*sp1la;
                sdlp = onec*sd1la;
                stlp = onec*st1la;

                phir = phi *pi180;

                msisa1.maps.perts.rig(h, phir, &g0, &g, &re, &r0, &ri);

                msisa1.maps.perts.iperts.rras.geocenttogeodet(ri*cos(phir), ri*sin(phir),
                    &gdlat, &gdhgt, req, rpo);


/*
                msisa1.maps.perts.iperts.inits1.out << fixed << setw(9) << setprecision(3) << h
                    << setw(8) << phi << setw(9) << thet << scientific << setw(11) << pmean <<
                    setw(12) << dmean << fixed << setw(7) << setprecision(1) << tmean <<
                    setw(7) << umean << setw(7) << vmean << setw(7) << setprecision(3) <<
                    wmean << " Mean" << '\n' << setw(9) << ri << setw(8) << gdlat << setw(17) <<
                    setprecision(2) << pghp << "%" << setw(11) << dghp << "%" << setw(8) <<
                    tghp << "%" << setw(26) << "M-76" << '\n' << setw(10) << setprecision(1) << elt <<
                    setw(7) << rra_id << setw(9) << setprecision(4) << rrawt << setw(8) << setprecision(2) <<
                    prsp << "%" << setw(11) << drsp << "%" << setw(8) << trsp << "%" << setw(7) <<
                    setprecision(1) << ru1sa << setw(7) << rv1sa <<
                    setw(12) << "ranS" << '\n' << setw(34) << setprecision(2) << spsp << "%" <<
                    setw(11) << sdsp << "%" << setw(8) << stsp << "%" << setw(7) << setprecision(1) << su1sa <<
                    setw(7) << msisa1.maps.perts.sv1s << setw(12) << "sigS" << '\n' <<
                    " Wind and SoS" << setw(21) << setprecision(2) << prlp << "%" << setw(11) <<
                    drlp << "%" << setw(8) << trlp << "%" << setw(7) << setprecision(1) << ru1la <<
                    setw(7) << rv1la << setw(12) << "ranL" << '\n' << " ------------" <<
                    setw(21) << setprecision(2) << splp << "%" << setw(11) << sdlp << "%" <<
                    setw(8) << stlp << "%" << setw(7) << setprecision(1) << su1la <<
                    setw(7) << sv1la << setw(12) << "sigL" << '\n' << " Ruv =  " <<
                    setw(5) << setprecision(3) << uvth << setw(21) <<
                    setprecision(2) << prhp << "%" << setw(11) << drhp << "%" << setw(8) <<
                    trhp << "%" << setw(7) << setprecision(1) << urh1a <<
                    setw(7) << vrh1a << setw(7) << setprecision(2) << rw1 << " ranT" << '\n' << " SpdAv= "
                    << setw(6) << setprecision(1) << spdgh << setw(20) << setprecision(2) << sphp << "%" << setw(11) <<
                    sdhp << "%" << setw(8) << sthp << "%" << setw(7) << setprecision(1) << su1 <<
                    setw(7) << sv1 << setw(7) << setprecision(2) << sw1 << " sigL" << '\n' <<
                    " SpdSd=" << setw(6) << setprecision(1) << sdsph << setw(24) << scientific << setprecision(3) << pmpert << setw(12) << dmpert <<
                    setw(7) << fixed << setprecision(1) << tmpert << setw(7) << umpert << setw(7) << vmpert << setw(7) << setprecision(2)
                    << wmpert << " Tot." << '\n' << " SoSav=" << setw(6) << setprecision(1) << csp0 << setw(21) << setprecision(2) <<
                    php << "%" << setw(11) << dhp << "%" << setw(8) << thp << "%" << setw(26) << "T-76" <<
                    '\n' << " SoSpt=" << setw(6) << setprecision(1) << csp << setw(24) << setprecision(3) <<
                    scientific << eoft << setw(12) << rhov << fixed << setprecision(1) << setw(7) << tdmean <<
                    setw(20) << rhp << "%" << " H2O" << '\n' << setw(37) << scientific << setprecision(3) <<
                    seoft << setw(12) << srhov << fixed << setprecision(1) << setw(7) << stdd << setw(20) <<
                    srhp << "%" << " sigH" <<
                    '\n';
*/

                *dmout = dmean;
                *pmout = pmean;
                *tmout = tmean;
                *umout = umean;
                *vmout = vmean;
                *wmout = wmean;
                *dpout = dmpert;
                *ppout = pmpert;
                *tpout = tmpert;
                *upout = umpert;
                *vpout = vmpert;
                *wpout = wmpert;
                *psout = pstd1 * 100;
                *dsout = dstd1 * 100;
                *tsout = tstd1*tmean;
                *usout = ustd1;
                *vsout = vstd1;
                *wsout = wstd1;
                *psmall = rp1sa;
                *dsmall = rd1sa;
                *tsmall = rt1sa;
                *usmall = ru1sa;
                *vsmall = rv1sa;
                *wsmall = rw1;
                *sosmean = csp0;
                *sospert = csp;


                h1 = h;
                phi1 = phi;
                thet1 = thet;
                time1 = timec;

            }



            else if (initonce == 0) {


            

                h = hgt;
                phi = lat;
                thet = lon;
                elt = time;
                timec = time;
                
                if (monte1 > 0){

                    if (iupdate1 > 0 && cm > 0){

                        dphi1 = phi - phi1;
                        dthet1 = thet - thet1;
                        dhgt2 = h - h1;
                        delt1 = timec - time1;
                        msisa1.maps.perts.elt = elt;
                        h1 = h;
                        phi1 = phi;
                        thet1 = thet;
                        time1 = timec;

                    }
                }

                else if (iupdate1 > 0) {

                    dphi1 = phi - phi1;
                    dthet1 = thet - thet1;
                    dhgt2 = h - h1;
                    delt1 = timec - time1;
                    msisa1.maps.perts.elt = elt;
                    h1 = h;
                    phi1 = phi;
                    thet1 = thet;
                    time1 = timec;

                }
                msisa1.maps.perts.elt = elt;

                //dphi = msisa.maps.perts.iperts.inits1.dphi;
                //dthet = msisa.maps.perts.iperts.inits1.dthet;


                //Interpret input height as radius if h > 6000
                if (h > 6000.0){
                    //Get local Earth radius r0
                    phir = phi*pi180;
                    msisa1.maps.perts.rig(0.0, phir, &g0, &g, &re, &r0, &ri);
                    h = h - r0;
                }

                //Terminate if height < -30 m below sea level
                if (h < (-0.031)){
                    cout << "Height below -30 m sea level, h = " << h << '\n';
                    exit(1);
                }

                //Set nm = 1, to calculate perturbations normally.
                nm = 1;
                spdavg = 0.0;

                //Adjust phi, thet, and dphi if trajectory crossed the pole.
                if (abs(phi) > 90.0){
                    phi = copysign(180.0 - abs(phi), phi);
                    dphi = -dphi;
                    thet = thet + 180.0;

                }

                if (thet < (-180.0)) thet = thet + 360.0;
                if (thet >= 180.0) thet = thet - 360.0;
                
                //If h < 40.0 call the gethgs member function from the NCEP class to get
                //the height at the 10 mb (hg2) and 20 mb (hg1) level
                if (h < 40.0){
                    msisa1.maps.perts.iperts.ncps.gethgs(phi, thet, &hg1, &hg2);
                }

                //If height <= height of 10 mb level use NCEP data
                if (h <= hg2){

                    //Compute NCEP data values by calling ncep member function
                    ncep();
                    dtz1 = msisa1.maps.perts.iperts.ncps.dtz;
                    //Get mean and sigma water vapor volume mixing ratio for NCEP
                    waterg = onemeg*vpn / (pnmean - vpn);
                    sigwater = waterg*svpn / vpn;

                    //Use only NCEP values if below height hg1
                    if (h < hg1){
                        pmean = pnmean;
                        dmean = dnmean;
                        tmean = tnmean;
                        umean = unmean;
                        vmean = vnmean;
                        wmean = wnmean;

                    }
                    else {
                        //Fair between NCEP and middle-atmosphere values if height
                        //between hg1 and hg2

                        //Call map member function for calculating values from MAP data.
                        map();

                        //Call intruv member function from InitP class to calculate standard
                        //deviation of winds from MAP data.  Used to calculate spdavg and 
                        //spdsd.
                        msisa1.maps.perts.iperts.intruv(ur,
                            vr, h, phi, &su, &sv);
                        su = sqrt((abs(su)));
                        sv = sqrt(abs(sv));

                        //call fair member function to fair between NCEP and MAP
                        fair(1, hg1, pnmean, dnmean, tnmean, unmean, vnmean, wnmean, hg2,
                            pmean1, dmean1, tmean1, umean1, vmean1, wmean1, h, &pmm,
                            &dmm, &tmm, &umm, &vmm, &wmm, &czi);
                        fair(2, hg1, spg, sdg, stg, sug, svg, swg, hg2, sp, sd, st, su, sv,
                            sw, h, &spj, &sdj, &stj, &suj, &svj, &swj, &czi);

                        pmean = pmm;
                        dmean = dmm;
                        tmean = tmm;
                        umean = umm;
                        vmean = vmm;
                        wmean = wmm;

                        if ((tmean1 - tnmean) != 0.0){
                            ffac = (tmean - tnmean) / (tmean1 - tnmean);
                            dtz1 = msisa1.maps.perts.iperts.ncps.dtz + ffac*(dtzm -
                                msisa1.maps.perts.iperts.ncps.dtz);
                        }

                        //Apply ruscale to standard deviation of u and v wind components.
                        suj = ruscale1*suj;
                        svj = ruscale1*svj;

                        //Calculate a faired value for wind speed and wind speed standard deviation.
                        FS = pow(suj, 2.0) + pow(svj, 2.0);
                        spdavg = czi*spdavg + (1.0 - czi)*sqrt(pow(umean, 2.0) + pow(vmean, 2.0) + 0.605*FS);
                        spdsd = czi*spdsd + (1.0 - czi)*sqrt(0.395*FS);

                    }

                }
                //Use MET, MSIS, or JB2008 thermosphere model if height above hj1, 90 km.
                else if (h >= hj1){

                    //Call thermosphere model based on user-selected input 'itherm'.
                    if (itherm1 == 1){
                        met();
                        dtz1 = msisa1.maps.perts.iperts.mets.dtz;
                        dmdz1 = msisa1.maps.perts.iperts.mets.dmdz;
                    }
                    else if (itherm1 == 2){
                        msis();
                        dtz1 = msisa1.dtz;
                    }
                    else if (itherm1 == 3){
                        jb2008();
                        dtz1 = msisa1.jb2008.dtz;
                    }

                    //Use only thermosphere model data if height above hj2, 120 km.
                    if (h >= hj2){
                        pmean = pmean2;
                        dmean = dmean2;
                        tmean = tmean2;
                        umean = umean2;
                        vmean = vmean2;
                        wmean = wmean2;
                        Umean = umean2;
                        Vmean = vmean2;
                    }
                    else {
                        //Fair between thermosphere and middle-atmosphere values
                        //if height between hj1 and hj2.
                        map();
                        fair(1, hj1, pmean1, dmean1, tmean1, umean1, vmean1, wmean1, hj2,
                            pmean2, dmean2, tmean2, umean2, vmean2, wmean2, h, &pmm, &dmm,
                            &tmm, &umm, &vmm, &wmm, &czi);


                        pmean = pmm;
                        dmean = dmm;
                        tmean = tmm;
                        umean = umm;
                        vmean = vmm;
                        wmean = wmm;
                        Umean = umm;
                        Vmean = vmm;

                        if ((tmean1 - tmean2) != 0.0){
                            ffac = (tmean - tmean2) / (tmean1 - tmean2);
                            dtz1 = dtz1 + ffac*(dtzm - dtz1);
                        }
                    }
                }
                else {
                    //Use only middle-atmosphere values if height between hg2 and 
                    //hj1.
                    map();
                    pmean = pmean1;
                    dmean = dmean1;
                    tmean = tmean1;
                    umean = umean1;
                    vmean = vmean1;
                    wmean = wmean1;
                    Umean = umean1;
                    Vmean = vmean1;
                    dtz1 = dtzm;
                }


                //Call speconc member function to calculate species concentration data.
                speconc();

                pert();

                //Use RRA data if height <= 70.0 and user-selected input variable iurra > 0.
                
                if ((h <= 70.0) & (iurra1 > 0)){

                    phir = phi*pi180;
                    msisa1.maps.perts.rig(h, phir, &g0, &g, &re, &r0, &ri1);

                    pgh = pmean;
                    dgh = dmean;
                    tgh = tmean;
                    ugh = umean;
                    vgh = vmean;

                    //Call rramean memeber function from RRA class to calculate RRA mean data.
                    msisa1.maps.perts.iperts.rras.rramean(h, phi, thet, mn, r0, &pgh,
                        &dgh, &tgh, &ugh, &vgh, rra_id, &rrawt);

                    if (msisa1.maps.perts.iperts.rras.z1[msisa1.maps.perts.iperts.rras.num1 - 1]){
                        urramean = ugh;
                        vrramean = vgh;
                    }

                    if (msisa1.maps.perts.iperts.rras.z2[msisa1.maps.perts.iperts.rras.num2 - 1]){
                        prramean = pgh;
                        drramean = dgh;
                        trramean = tgh;
                    }


                    //Revise GRAM vapor pressure, dew point, RH, mixing ratio
                    //and standard deviations by weighted average with RRA data
                    int num3b = msisa1.maps.perts.iperts.rras.num3;
                    if (h <= msisa1.maps.perts.iperts.rras.z3[num3b - 1]){
                        grmwt = 1.0 - msisa1.maps.perts.iperts.rras.rrawt3;

                        eoft = rrawt*msisa1.maps.perts.iperts.rras.vprra + grmwt*eoft;
                        seoft = rrawt*msisa1.maps.perts.iperts.rras.svprra + grmwt*seoft;
                        tdmean = rrawt*msisa1.maps.perts.iperts.rras.tdrra + grmwt*tdmean;
                        stdd = rrawt*msisa1.maps.perts.iperts.rras.stdrra + grmwt*stdd;
                        water = 1.0e+06*eoft / (pmean - eoft);

                        dest = 0.5*msisa1.maps.d2edt2(msisa1.maps.perts.iperts.rras.trra,
                            msisa1.maps.perts.iperts.rras.prra)*msisa1.maps.perts.iperts.rras.strra;
                        rhrra = 100.0*msisa1.maps.perts.iperts.rras.vprra / (msisa1.maps.wexler(msisa1.maps.perts.iperts.rras.trra,
                            msisa1.maps.perts.iperts.rras.prra) + dest);
                        rhrra = max(3.0, rhrra);
                        rhrra = min(100.0, rhrra);
                        rhp = rrawt*rhrra + grmwt*rhp;
                        rhov = eps*eoft / (r0a*tmean);
                        if (eoft <= 0.0){
                            sigwater = 0.0;
                            shrra = 0.0;
                            srhov = 0.0;
                        }
                        else{
                            sigwater = water*seoft / eoft;
                            sigest = msisa1.maps.dedt(tmean, pmean)*msisa1.maps.perts.sth*tmean / eoft;

                            srhov = rhov*sqrt(pow((seoft / eoft), 2.0) +
                                pow((stdd / tdmean), 2.0));
                            srhf = 1.43 + 0.315*log10(msisa1.maps.perts.iperts.rras.prra / 1.0e+05);
                            corr = 0.85 - 0.7*pow(cos(pi180*phi), 6.0);
                            srhrra = rhrra*sqrt(pow((seoft / eoft), 2.0) + pow(sigest, 2.0) -
                                2.0*corr*sigest*seoft / eoft) / srhf;
                            srhrra = min(50.0, srhrra);
                            srhrra = min(1.05*rhrra, srhrra);
                            srhrra = max(0.05*rhrra, srhrra);
                            srhp = rrawt*srhrra + grmwt*srhp;
                        }

                        ppmh2o = water;
                        h2ond = water*ppmtond;


                    }
                    //If height <= 27.0, calcuate a weighted RRA surface dewpoint mean and
                    //standard deviation.
                    if (h <= 27.0){
                        tdsrf = grmwt*tdmean + rrawt*msisa1.maps.perts.iperts.rras.tdsrf;
                        stdsrf = grmwt*stdd + rrawt*msisa1.maps.perts.iperts.rras.stdsrf;
                    }


                    double ztop, ztopm;
                    ztop = ztop1;
                    ztopm = ztop - 5.0;

                    double wdum = 0.0, wdum1, prg, drg, trg, urg, vrg, cz1, del, del1, del2;
                    if (h >= ztopm && h <= ztop && iyrra1 == 3){

                        del = urramean - urramean1;
                        del1 = vrramean - vrramean1;
                        del2 = trramean - trramean1;

                        
                        //RRA Fair
                        fair(1, ztopm, prramean, drramean, trramean, urramean, vrramean, wdum,
                            ztop, pmean, dmean, tmean, umean, vmean, wdum, h, &prg, &drg, &trg,
                            &urg, &vrg, &wdum1, &cz1);

                        pmean = prg;
                        dmean = drg;
                        tmean = trg;
                        umean = urg;
                        vmean = vrg;

                    }

                    else {

                        pmean = prramean;
                        dmean = drramean;
                        tmean = trramean;
                        umean = urramean;
                        vmean = vrramean;

                    }

                    if (rrawt == 0) {
                        pmean = pgh;
                        dmean = dgh;
                        tmean = tgh;
                        umean = ugh;
                        vmean = vgh;
                    }

                }




                //Rescale non-water-vapor concentrations to correct for the effects of 
                //interpolation, fairing, and water vapor
                totppm = ppmo3 + ppmn2o + ppmco + ppmch4 + ppmco2 + ppmn2 + ppmo2 +
                    ppmo + ppmar + ppmhe + ppmh + ppmn;

                ppmscale = (1.0e+06 - ppmh2o) / totppm;

                ppmo3 = ppmo3*ppmscale;
                ppmn2o = ppmn2o*ppmscale;
                ppmco = ppmco*ppmscale;
                ppmch4 = ppmch4*ppmscale;
                ppmco2 = ppmco2*ppmscale;
                ppmn2 = ppmn2*ppmscale;
                ppmo2 = ppmo2*ppmscale;
                ppmo = ppmo*ppmscale;
                ppmar = ppmar*ppmscale;
                ppmhe = ppmhe*ppmscale;
                ppmh = ppmh*ppmscale;
                ppmn = ppmn*ppmscale;
                ppmtond = avn*pmean / (8314.472e+6*tmean);

                h2ond = ppmh2o*ppmtond;
                o3nd = ppmo3*ppmtond;
                n2ond = ppmn2o*ppmtond;
                cond = ppmco*ppmtond;
                ch4nd = ppmch4*ppmtond;
                co2nd = ppmco2*ppmtond;
                n2nd = ppmn2*ppmtond;
                o2nd = ppmo2*ppmtond;
                ond = ppmo*ppmtond;
                arnd = ppmar*ppmtond;
                hend = ppmhe*ppmtond;
                hnd = ppmh*ppmtond;
                nnd = ppmn*ppmtond;

                totnd = h2ond + o3nd + n2ond + cond + ch4nd + co2nd + n2nd + o2nd + ond
                    + arnd + hend + hnd + nnd;
                mwnd = (h2ond*wth2o + o3nd*wto3 + n2ond*wtn2o + cond*wtco + ch4nd*wtch4 +
                    co2nd*wtco2 + n2nd*wtn2 + o2nd*wto2 + ond*wto + arnd*wtar + hend*wthe +
                    hnd*wth + nnd*wtn) / totnd;

                //If user-selected variable iaux > 0 use available auxiliary profile data.

                double profout, tout, pout, dout, uout, vout,
                    sitenear = msisa1.maps.perts.iperts.inits1.sitenear,
                    sitelim = msisa1.maps.perts.iperts.inits1.sitelim;
                string home1 = msisa1.maps.perts.iperts.inits1.home;
                string profile1 = msisa1.maps.perts.iperts.inits1.profile;

                if (msisa1.maps.perts.iperts.inits1.iaux > 0){
                    //msisa.maps.perts.iperts.auxs.rdprof(sitenear, sitelim, home1, profile1);
                    msisa1.maps.perts.iperts.auxs.profterp(h, phi, thet, tmean, pmean, dmean, umean,
                        vmean, &tout, &pout, &dout, &uout, &vout, &profout);

                    pmean = pout;
                    dmean = dout;
                    tmean = tout;
                    vmean = vout;
                    umean = uout;

                }

                //Call the member function pert to calculate perturbation at current 
                //state.


                //Calculate total perturbed values added to mean data.
                pmpert = pmean * (1 + ppert);
                dmpert = dmean * (1 + dpert);
                tmpert = tmean * (1 + tpert);
                umpert = umean + upert;
                vmpert = vmean + vpert;
                wmpert = wmean + wpert;

                //Insure wind component magnitudes < 0.7 times sound speed
                splim = 0.7*sqrt(1.4*pmpert / dmpert);
                if (abs(umpert) > splim) umpert = copysign(splim, umpert);
                if (abs(vmpert) > splim) vmpert = copysign(splim, vmpert);

                //Calculate average wind speed and wind speed standard deviation.
                //Use wind speed data if it is available.
                if (spdavg > 0){
                    spdgh = spdavg;
                    sdsph = spdsd;
                }
                else{
                    //Calculate wind speed if data is not available.
                    msisa1.maps.perts.iperts.intruv(ur,
                        vr, h, phi, &su, &sv);
                    su = sqrt(abs(su))*ruscale1;
                    sv = sqrt(abs(sv))*ruscale1;
                    FS = pow(su, 2.0) + pow(sv, 2.0);
                    spdgh = sqrt(pow(Umean, 2.0) + pow(Vmean, 2.0) + 0.605*FS);
                    sdsph = sqrt(0.3950*FS);
                }
                //Weight RRA wind speed data when it is available.
                if (msisa1.maps.perts.iperts.rras.sitewgt > 0.0 && h <= msisa1.maps.perts.iperts.rras.z1[msisa1.maps.perts.iperts.rras.num1 - 1]){
                    rrawts = msisa1.maps.perts.iperts.rras.rrawt1;
                    grmwts = 1.0 - rrawts;
                    spdgh = rrawts*msisa1.maps.perts.iperts.rras.avspdrra + grmwts*spdgh;
                    sdsph = rrawts*msisa1.maps.perts.iperts.rras.sdspdrra + grmwts*sdsph;

                }

                if ((msisa1.maps.perts.iperts.inits1.iaux) && (profout > 0.0)){
                    FS = pow(msisa1.maps.perts.suh, 2.0) + pow(msisa1.maps.perts.svh, 2.0);
                    spdgh = (sqrt(pow(umean, 2.0) + pow(vmean, 2.0) + 0.605*FS)*profout) + spdavg*(1 - profout);
                    sdsph = (sqrt(0.3950*FS)*profout) + spdsd*(1 - profout);
                }

                

                //Gas constant and ratio of specific heats
                gasconst = pmean / (dmean*tmean);
                cpmn = (1.4 / 0.4)*gasconst;
                //Sound speed (m/s) from mean and perturbed temperature
                csp0 = sqrt(1.4*gasconst*tmean);
                csp = sqrt(1.4*gasconst*tmpert);

                //Pressure scale height (m), density scale height (m)
                msisa1.maps.perts.rig(h, phir, &g0, &g, &re, &r0, &ri);
                hgtp = pmean / (dmean*g);
                if (h <= hg2) dtz1 = dtz1 / 1000.0;
                if (h <= hj1) {
                    hgtd = hgtp / (1.0 + hgtp*dtz1 / tmean);
                }
                else {
                    hgtd = hgtp / (1.0 + hgtp*dtz1 / tmean - hgtp*dmdz1 / wtmol);
                }
/*
                //Output species concentration data to "species.txt"
                species << fixed << setw(9) << setprecision(3) << h << setw(8) << setprecision(3) <<
                    phi << setw(9) << setprecision(3) << thet << scientific << setw(12) << setprecision(3) <<
                    ppmh2o << setw(11) << setprecision(3) << h2ond << " |" << setw(11) << setprecision(3) <<
                    ppmo3 << setw(11) << setprecision(3) << o3nd << "  H2O |  O3" <<
                    '\n';
                species << scientific << setw(38) << setprecision(3) << ppmn2o << setw(11) <<
                    setprecision(3) << n2ond << " |" << setw(11) << setprecision(3) << ppmco <<
                    setw(11) << setprecision(3) << cond << "  N2O |  CO" <<
                    '\n';
                species << scientific << setw(38) << setprecision(3) << ppmch4 << setw(11) <<
                    setprecision(3) << ch4nd << " |" << setw(11) << setprecision(3) << ppmco2 <<
                    setw(11) << setprecision(3) << co2nd << "  CH4 | CO2" <<
                    '\n';
                species << scientific << setw(38) << setprecision(3) << ppmn2 << setw(11) <<
                    setprecision(3) << n2nd << " |" << setw(11) << setprecision(3) << ppmo2 <<
                    setw(11) << setprecision(3) << o2nd << "   N2 |  O2" <<
                    '\n';
                species << scientific << setw(38) << setprecision(3) << ppmo << setw(11) <<
                    setprecision(3) << ond << " |" << setw(11) << setprecision(3) << ppmar <<
                    setw(11) << setprecision(3) << arnd << "    O |  Ar" <<
                    '\n';
                species << scientific << setw(38) << setprecision(3) << ppmhe << setw(11) <<
                    setprecision(3) << hend << " |" << setw(11) << setprecision(3) << ppmh <<
                    setw(11) << setprecision(3) << hnd << "   He |   H" <<
                    '\n';
                species << scientific << setw(38) << setprecision(3) << ppmn << setw(11) <<
                    setprecision(3) << nnd << " | " << "MW=" << fixed << setw(6) << setprecision(3) << mwnd <<
                    scientific << setw(12) << setprecision(3) << totnd << "    N | Tot" <<
                    '\n';

                species << " -------- ------- --------  ---------- ----------   ---------- ----------  ---- ---- " << '\n';

                //Output data to "Special.txt".
                output << fixed << setw(10) << setprecision(2) << elt << setw(9) << setprecision(3) <<
                    h << setw(10) << setprecision(5) << phi << setw(11) << setprecision(5) << thet <<
                    scientific << setw(12) << setprecision(4) << dmean << setw(12) << setprecision(4) <<
                    pmean << fixed << setw(8) << setprecision(2) << tmean << setw(8) << setprecision(2) << umean <<
                    setw(8) << setprecision(2) << vmean << scientific << setw(12) << setprecision(4) << dmpert <<
                    setw(12) << setprecision(4) << pmpert << fixed << setw(8) << setprecision(2) << tmpert <<
                    setw(8) << setprecision(2) << umpert << setw(8) << setprecision(2) << vmpert << setw(7) <<
                    setprecision(2) << msisa1.maps.perts.sdh * 100 << setw(7) << setprecision(2) << msisa1.maps.perts.sph * 100 << setw(7) << setprecision(2) <<
                    tmean*msisa1.maps.perts.sth << setw(7) << setprecision(2) << msisa1.maps.perts.suh << setw(7) << setprecision(2) << msisa1.maps.perts.svh <<
                    setw(7) << setprecision(2) << swh << setw(7) << setprecision(2) << wmpert << setw(7) << setprecision(2) <<
                    spdgh << setw(7) << setprecision(2) << sdsph << setw(8) << setprecision(2) <<
                    csp0 << setw(8) << setprecision(2) << csp << setw(4) << msisa1.maps.perts.isev <<
                    '\n';
*/
                //Process data for Output data to Output.txt

                //stdatm member function from Atmod Class to calculate standard atmosphere
                stdatm(h, &t1, &p1, &d1);
                //Calculate percent deviation of GRAM mean from stadard atmosphere
                if (p1*d1*t1 > 0){
                    pghp = onec*(pmean - p1) / p1;
                    dghp = onec*(dmean - d1) / d1;
                    tghp = onec*(tmean - t1) / t1;
                    php = onec*(pmpert - p1) / p1;
                    dhp = onec*(dmpert - d1) / d1;
                    thp = onec*(tmpert - t1) / t1;
                }
                else {
                    pghp = 0.0;
                    dghp = 0.0;
                    tghp = 0.0;
                    php = 0.0;
                    dhp = 0.0;
                    thp = 0.0;
                }

                //Converts random p,d,t and standard deviations to percent
                prhp = onec*msisa1.maps.perts.prh;
                drhp = onec*msisa1.maps.perts.drh;
                trhp = onec*msisa1.maps.perts.trh;
                prsp = onec*msisa1.maps.perts.prhs;
                drsp = onec*msisa1.maps.perts.drhs;
                trsp = onec*msisa1.maps.perts.trhs;
                prlp = onec*msisa1.maps.perts.prhl;
                drlp = onec*msisa1.maps.perts.drhl;
                trlp = onec*msisa1.maps.perts.trhl;
                sphp = onec*msisa1.maps.perts.sph;
                sdhp = onec*msisa1.maps.perts.sdh;
                sthp = onec*msisa1.maps.perts.sth;
                splp = onec*msisa1.maps.perts.sphl;
                sdlp = onec*msisa1.maps.perts.sdhl;
                stlp = onec*msisa1.maps.perts.sthl;
                spsp = onec*msisa1.maps.perts.sphs;
                sdsp = onec*msisa1.maps.perts.sdhs;
                stsp = onec*msisa1.maps.perts.sths;

                phir = phi *pi180;

                msisa1.maps.perts.rig(h, phir, &g0, &g, &re, &r0, &ri);

                msisa1.maps.perts.iperts.rras.geocenttogeodet(ri*cos(phir), ri*sin(phir),
                    &gdlat, &gdhgt, req, rpo);
/*
                msisa1.maps.perts.iperts.inits1.out << "-------- ------- -------- --------- ---------- ------ ------ ------ ------ ----" << '\n';
                msisa1.maps.perts.iperts.inits1.out << fixed << setw(9) << setprecision(3) << h
                    << setw(8) << phi << setw(9) << thet << scientific << setw(11) << pmean <<
                    setw(12) << dmean << fixed << setw(7) << setprecision(1) << tmean <<
                    setw(7) << umean << setw(7) << vmean << setw(7) << setprecision(3) <<
                    wmean << " Mean" << '\n' << setw(9) << ri << setw(8) << gdlat << setw(17) <<
                    setprecision(2) << pghp << "%" << setw(11) << dghp << "%" << setw(8) <<
                    tghp << "%" << setw(26) << "M-76" << '\n' << setw(10) << setprecision(1) << elt <<
                    setw(7) << rra_id << setw(9) << setprecision(4) << rrawt << setw(8) << setprecision(2) <<
                    prsp << "%" << setw(11) << drsp << "%" << setw(8) << trsp << "%" << setw(7) <<
                    setprecision(1) << msisa1.maps.perts.urhs << setw(7) << msisa1.maps.perts.vrhs <<
                    setw(12) << "ranS" << '\n' << setw(34) << setprecision(2) << spsp << "%" <<
                    setw(11) << sdsp << "%" << setw(8) << stsp << "%" << setw(7) << setprecision(1) << msisa1.maps.perts.suhs <<
                    setw(7) << msisa1.maps.perts.svhs << setw(12) << "sigS" << '\n' <<
                    " Wind and SoS" << setw(21) << setprecision(2) << prlp << "%" << setw(11) <<
                    drlp << "%" << setw(8) << trlp << "%" << setw(7) << setprecision(1) << msisa1.maps.perts.urhl <<
                    setw(7) << msisa1.maps.perts.vrhl << setw(12) << "ranL" << '\n' << " ------------" <<
                    setw(21) << setprecision(2) << splp << "%" << setw(11) << sdlp << "%" <<
                    setw(8) << stlp << "%" << setw(7) << setprecision(1) <<msisa1.maps.perts.suhl <<
                    setw(7) << msisa1.maps.perts.svhl << setw(12) << "sigL" << '\n' << " Ruv =  " <<
                    setw(5) << setprecision(3) << msisa1.maps.perts.uvt2 << setw(21) <<
                    setprecision(2) << prhp << "%" << setw(11) << drhp << "%" << setw(8) <<
                    trhp << "%" << setw(7) << setprecision(1) << msisa1.maps.perts.urh <<
                    setw(7) << msisa1.maps.perts.vrh << setw(7) << setprecision(2) << msisa1.maps.perts.wrh << " ranT" << '\n' << " SpdAv= "
                    << setw(6) << setprecision(1) << spdgh << setw(20) << setprecision(2) << sphp << "%" << setw(11) <<
                    sdhp << "%" << setw(8) << sthp << "%" << setw(7) << setprecision(1) << msisa1.maps.perts.suh <<
                    setw(7) << msisa1.maps.perts.svh << setw(7) << setprecision(2) << sw1 << " sigT" << '\n' <<
                    " SpdSd=" << setw(6) << setprecision(1) << sdsph << setw(24) << scientific << setprecision(3) << pmpert << setw(12) << dmpert <<
                    setw(7) << fixed << setprecision(1) << tmpert << setw(7) << umpert << setw(7) << vmpert << setw(7) << setprecision(2)
                    << wmpert << " Tot." << '\n' << " SoSav=" << setw(6) << setprecision(1) << csp0 << setw(21) << setprecision(2) <<
                    php << "%" << setw(11) << dhp << "%" << setw(8) << thp << "%" << setw(26) << "T-76" <<
                    '\n' << " SoSpt=" << setw(6) << setprecision(1) << csp << setw(24) << setprecision(3) <<
                    scientific << eoft << setw(12) << rhov << fixed << setprecision(1) << setw(7) << tdmean <<
                    setw(20) << rhp << "%" << " H2O" << '\n' << setw(37) << scientific << setprecision(3) <<
                    seoft << setw(12) << srhov << fixed << setprecision(1) << setw(7) << stdd << setw(20) <<
                    srhp << "%" << " sigH" <<
                    '\n';
*/
                *dmout = dmean;
                *pmout = pmean;
                *tmout = tmean;
                *umout = umean;
                *vmout = vmean;
                *wmout = wmean;
                *dpout = dmpert;
                *ppout = pmpert;
                *tpout = tmpert;
                *upout = umpert;
                *vpout = vmpert;
                *wpout = wmpert;
                *psout = msisa1.maps.perts.sph * 100;
                *dsout = msisa1.maps.perts.sdh * 100;
                *tsout = msisa1.maps.perts.sth*tmean;
                *usout = msisa1.maps.perts.suh;
                *vsout = msisa1.maps.perts.svh;
                *wsout = swh;
                *psmall = msisa1.maps.perts.prhs;
                *dsmall = msisa1.maps.perts.drhs;
                *tsmall = msisa1.maps.perts.trhs;
                *usmall = msisa1.maps.perts.urhs;
                *vsmall = msisa1.maps.perts.vrhs;
                *wsmall = wpert;
                *sosmean = csp0;
                *sospert = csp;

                //h1 = hgt;
                //phi1 = lat;
                //thet1 = lon;
                //time1 = time;

            }

        };
};

vector<Atm_*> Atm_Database;

int createAtm (const char* basePath_,     //string for base path of any data
                const char* atmosFile_,    //string for atmpath
                const char* rangeRefPath_, //string for RRA path

                int* randomScaleAtm, // monte-carlo seed variable
                int* randomScaleWindHoriz, // monte-carlo seed variable
                int* randomScaleWindVert, // monte-carlo seed variable
				
                double* solarFlux,
                double* solarFluxAv,
                double* geomagIdx, 
                double* euvIndex, 
                double* euvIndexAv, 
                double* mgIndex, 
                double* mgIndexAv, 
                double* xRayIndex, 
                double* xRayIndexAv, 
                double* tempChange, 
                double* surfRough, 
				
                int*    year,
				int*    month,
				int*    day,
				int*    hour,
				int*    min,
				double* sec) {

	string basePath(basePath_);   
	string atmosFile(atmosFile_);
	string rangeRefPath(rangeRefPath_);
                    
	Atm_ * atms_local = new Atm_;

	atms_local->msisa1.maps.perts.iperts.inits1.atmpath = atmosFile; 
	atms_local->msisa1.maps.perts.iperts.inits1.NCEPpath = basePath + "NCEPdata\\FixedBin\\";
	atms_local->msisa1.maps.perts.iperts.inits1.rrapath = rangeRefPath;
	//atms_local->msisa1.maps.perts.iperts.inits1.nr1 = *randomScaleAtm;
	atms_local->msisa1.maps.perts.iperts.inits1.ap = *geomagIdx; 
	atms_local->msisa1.maps.perts.iperts.inits1.f10 = *solarFlux;
	atms_local->msisa1.maps.perts.iperts.inits1.f10b = *solarFluxAv;
	atms_local->msisa1.maps.perts.iperts.inits1.s10 = *euvIndex;
	atms_local->msisa1.maps.perts.iperts.inits1.s10b = *euvIndexAv;
	atms_local->msisa1.maps.perts.iperts.inits1.xm10 = *mgIndex;
	atms_local->msisa1.maps.perts.iperts.inits1.xm10b = *mgIndexAv;
	atms_local->msisa1.maps.perts.iperts.inits1.y10 = *xRayIndex;
	atms_local->msisa1.maps.perts.iperts.inits1.y10b = *xRayIndexAv;
	atms_local->msisa1.maps.perts.iperts.inits1.dstdtc = *tempChange;
	atms_local->msisa1.maps.perts.iperts.inits1.z0in = *surfRough;
	
	atms_local->msisa1.maps.perts.iperts.inits1.rpscale = *randomScaleAtm;
	atms_local->msisa1.maps.perts.iperts.inits1.ruscale = *randomScaleWindHoriz; 
	atms_local->msisa1.maps.perts.iperts.inits1.rwscale = *randomScaleWindVert;

	atms_local->msisa1.maps.perts.iperts.inits1.mn = *month;
	atms_local->msisa1.maps.perts.iperts.inits1.ida = *day;
	atms_local->msisa1.maps.perts.iperts.inits1.iyr = *year;
	atms_local->msisa1.maps.perts.iperts.inits1.ihro = *hour;
	atms_local->msisa1.maps.perts.iperts.inits1.mino = *min;
	atms_local->msisa1.maps.perts.iperts.inits1.seco = *sec;

	atms_local->initdata();
	Atm_Database.push_back(atms_local);
    int index = sizeof(Atm_Database)-1;
    return index;
};

void runAtm(int* index, int* initonce, double* hgt, double* lat, double* lon, double* time, 
double* dm,  double* pm, double* tm, double* um, double* vm, double* wm, 
double* dp, double* pp, double* tp, double* up, double* vp, double* wp, 
double* ds, double* ps, double* ts, double* us, double* vs, double* ws,  
double* dsm, double* psm, double* tsm, double* usm, double* vsm, double* wsm, 
double* sosm, double* sosp){        
       int iupdate = 1; 
       Atm_Database[*index]->traj2(*hgt, *lat, *lon, *time, iupdate, *initonce, dm,
                            pm, tm, um, vm, wm, dp, pp,
                            tp, up, vp, wp, ds, ps,
                            ts, us, vs, ws, dsm, psm,
                            tsm, usm, vsm, wsm, sosm, sosp);
}

void deleteAtm(Atm_* atm){

	if (!atm) {
		return;
	}
    else {
        atm = NULL;
		return;
	}

   
}

void finalize() {
    //std::cout<<"\ndeleting RPA_Local..";
    //std::cout.flush();
    if (Atm_Database.size()>0){
        for (int i = 0; i<Atm_Database.size(); i++){
	      deleteAtm(Atm_Database[i]);
        }
        Atm_Database.clear();
    }
}
/*
int main(){
    
}
*/

/*
int main(){
        using namespace std;
        string base_string = "C:\\Users\\vic-b\\Documents\\Victors\\Job\\Astos\\project\\EarthGRAM2016Version2_\\EarthGRAM2016Version2.0\\";
        string Atmos_File_Address = base_string + "IOfiles\\";         //Atmos_File_Address
        string rra = base_string + "RRAdata\\";                        //Range_Ref_Path_Address
        string nprpath = "output.txt";                                 //Output_Path_Address
        int nr1 = 10;                                             //Random_Scale_Address
        double f10 =230.0;                                           //Solar_Flux_SI_Address
        double f10b = 230.0;                                          //Solar_Flux_A_SI_Address
        double ap = 16.31;                                         //Geomag_Idx_Address
        double JulDat_Address = 10.0;                                  //JulDat_Address
        
         

        createAtm(&base_string, &Atmos_File_Address,  &rra, &nprpath,     &nr1, &f10, &f10b, &ap, &JulDat_Address);

        runAtm(0,1,50,10,10,10);

        createAtm(&base_string, &Atmos_File_Address,  &rra, &nprpath,    &nr1, &f10, &f10b, &ap, &JulDat_Address);
        runAtm(1,1,50,10,10,10);

        nr1 = 100;  
        createAtm(&base_string, &Atmos_File_Address,  &rra, &nprpath,      &nr1,  &f10, &f10b, &ap, &JulDat_Address);
        runAtm(2,1,50,10,10,10);
}
*/

#ifdef __cplusplus
}
#endif
