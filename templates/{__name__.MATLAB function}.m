function y = {__name__}(u, opts)
%{__UpperSnakeCaseName__} One-line summary (H1 line, searched by lookfor).
%   Y = {__UpperSnakeCaseName__}(U) ...
%   Y = {__UpperSnakeCaseName__}(U, Gain=G) ...
%
%   Inputs:
%     u        - input signal, column vector [unit]
%     opts.Gain - scalar gain [-] (default 1)
%
%   Outputs:
%     y        - output signal, same size as u [unit]
%
%   See also .

%   Project : {__project__}
%   Author  : {__author__} ({__email__})
%   Date    : {__date__}
%   Copyright (c) 2016-{__year__}, {__company__}. All rights reserved.

% The arguments block needs R2019b or later; name=value syntax needs R2021a.
arguments
    u (:,1) double {mustBeReal}
    opts.Gain (1,1) double {mustBeReal, mustBeFinite} = 1
end

y = opts.Gain * u;

end

%% Local functions -----------------------------------------------------------
