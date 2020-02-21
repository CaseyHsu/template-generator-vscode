----------------------------------------------------------------------------------
-- Company:        {__company__}
-- Engineer:       {__author__} ({__email__})
--
-- Create Date:    {__date__}
-- Module Name:    {__name__} - {__name__}_arch
-- Project Name:   {__project__}
-- Target Devices:
-- Tool versions:
-- Description:
--
-- Dependencies:
--
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
----------------------------------------------------------------------------------
--  Copyright (c) 2016-{__year__}, {__company__}
--  All rights reserved.
----------------------------------------------------------------------------------
-- Naming Conventions(PascalCaseName)
--   active low signals:                    "*_n"
--   clock signals:                         "inClk", "inClk_div#", "inClk_#x"
--   reset signals:                         "inRst", "inRst_n"
--   array signals:                         "*_ar"
--   generics:                              "C_*"
--   user defined types:                    "*_TYPE"
--   state machine next state:              "*_ns"
--   state machine current state:           "*_cs"
--   combinatorial signals:                 "*_com"
--   pipelined or register delay signals:   "*_d#"
--   counter signals:                       "*_cnt"
--   clock enable signals:                  "*_ce"
--   device pins:                           "*_pin"
--   ports:                                 "- Names begin with Uppercase"
--   processes:                             "*_PROCESS"
--   component instantiations:              "<ENTITY_>I_<#|FUNC>"
----------------------------------------------------------------------------------
library IEEE;
library UNISIM;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.NUMERIC_STD.ALL;
use UNISIM.VComponents.all;

entity {__PascalCaseName__} is
  Port
  (
    inClk : in  STD_LOGIC;
    inReset : in  STD_LOGIC;
    inName : in  STD_LOGIC;
    outName  : out  STD_LOGIC;
    inData16 : in  STD_LOGIC_VECTOR (15 downto 0);
    outData16 : out  STD_LOGIC_VECTOR (15 downto 0)
    -- DO NOT EDIT ABOVE THIS LINE ---------------------
  );
end {__PascalCaseName__};

architecture {__PascalCaseName__}_arch of {__PascalCaseName__} is

----------------------------------------------------------------------------------
--  Global signals define
----------------------------------------------------------------------------------
constant  cParameter : std_logic := '0';

signal regName: std_logic := '0';
signal regData16 : std_logic_vector(15 downto 0) := (others => '0');

-- Attributes
attribute clock_signal          : string;
attribute clock_signal of inClk : signal is "yes";
----------------------------------------------------------------------------------
--  Interface component define
----------------------------------------------------------------------------------

begin
----------------------------------------------------------------------------------
--  Functional description begin
----------------------------------------------------------------------------------
UPPER_SNAKE_CASE: process(inClk, inReset)
begin
  if inReset = '1' then
    regName <= '0';
    regData16 <= (others => '0');
  elsif rising_edge(inClk) then
    regName <= inName;
    regData16 <= inData16;
  end if;
end process;

----------------------------------------------------------------------------------
--  Assign output signals link
----------------------------------------------------------------------------------
outName   <= regName;
outData16 <= regData16;

----------------------------------------------------------------------------------
--  Interface component link
----------------------------------------------------------------------------------

end {__PascalCaseName__}_arch;
