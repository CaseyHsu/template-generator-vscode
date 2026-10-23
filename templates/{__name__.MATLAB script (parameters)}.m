%{__UpperSnakeCaseName__} Parameter initialization script for Simulink/PLECS models.
%   Run before the simulation (e.g. from the model's InitFcn callback).
%   Values left as NaN must be filled in; nothing here is a default motor.
%
%   Conventions: SI units; dq frame with q-axis leading d-axis by 90 deg;
%   theta_e = angle between d-axis and a-axis; motor convention (current
%   into the terminals is positive); amplitude-invariant Clarke/Park;
%   IPMSM: Ld < Lq.

%   Project : {__project__}
%   Author  : {__author__} ({__email__})
%   Date    : {__date__}
%   Copyright (c) 2016-{__year__}, {__company__}. All rights reserved.

%% Timing ---------------------------------------------------------------------
timing.fPwm   = NaN;              % PWM switching frequency [Hz]
timing.Ts     = 1 / timing.fPwm;  % control sample time, one update per PWM period [s]
timing.Tsim   = NaN;              % simulation stop time [s]

%% Motor ----------------------------------------------------------------------
motor.Rs      = NaN;              % stator resistance per phase [Ohm]
motor.Ld      = NaN;              % d-axis inductance [H]
motor.Lq      = NaN;              % q-axis inductance [H]
motor.psiF    = NaN;              % PM flux linkage, peak per phase [Wb]
motor.Pp      = NaN;              % pole PAIRS (not poles) [-]
motor.J       = NaN;              % rotor + load inertia [kg*m^2]
motor.B       = NaN;              % viscous friction [N*m*s/rad]

%% Inverter -------------------------------------------------------------------
inverter.Vdc  = NaN;              % DC-link voltage [V]
inverter.Tdead = NaN;              % dead time [s]

%% Controller -----------------------------------------------------------------
% Current-loop PI by pole-zero cancellation of the R-L plant:
%   Kp = wc*L, Ki = wc*Rs (C(s) = Kp + Ki/s), closed loop ~ wc/(s + wc).
% Assumes continuous-time design, constant L (no saturation), decoupled dq,
% and neglects the ~1.5*Ts computation + PWM delay; keep wc well below 1/Ts.
ctrl.wcI      = NaN;              % current-loop bandwidth [rad/s]
ctrl.KpId     = ctrl.wcI * motor.Ld;
ctrl.KiId     = ctrl.wcI * motor.Rs;
ctrl.KpIq     = ctrl.wcI * motor.Lq;
ctrl.KiIq     = ctrl.wcI * motor.Rs;

%% Checks ---------------------------------------------------------------------
% Lists every NaN left in the parameter structs.
chk = struct('timing', timing, 'motor', motor, 'inverter', inverter, 'ctrl', ctrl);
for name = fieldnames(chk).'
    st = chk.(name{1});
    f = fieldnames(st);
    missing = f(cellfun(@(k) any(isnan(st.(k))), f));
    if ~isempty(missing)
        warning('%s: not set: %s', name{1}, strjoin(missing.', ', '));
    end
end
clear chk name st f missing
