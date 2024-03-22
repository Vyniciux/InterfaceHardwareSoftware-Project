	component pcihellocore is
		port (
			buttons_external_connection_export       : in  std_logic_vector(7 downto 0)  := (others => 'X'); -- export
			hex_display_l_external_connection_export : out std_logic_vector(31 downto 0);                    -- export
			hex_display_r_external_connection_export : out std_logic_vector(31 downto 0);                    -- export
			leds_verdes_external_connection_export   : out std_logic_vector(31 downto 0);                    -- export
			pcie_hard_ip_0_pcie_rstn_export          : in  std_logic                     := 'X';             -- export
			pcie_hard_ip_0_powerdown_pll_powerdown   : in  std_logic                     := 'X';             -- pll_powerdown
			pcie_hard_ip_0_powerdown_gxb_powerdown   : in  std_logic                     := 'X';             -- gxb_powerdown
			pcie_hard_ip_0_refclk_export             : in  std_logic                     := 'X';             -- export
			pcie_hard_ip_0_rx_in_rx_datain_0         : in  std_logic                     := 'X';             -- rx_datain_0
			pcie_hard_ip_0_tx_out_tx_dataout_0       : out std_logic;                                        -- tx_dataout_0
			red_leds_external_connection_export      : out std_logic_vector(31 downto 0);                    -- export
			switches_external_connection_export      : in  std_logic_vector(31 downto 0) := (others => 'X')  -- export
		);
	end component pcihellocore;

	u0 : component pcihellocore
		port map (
			buttons_external_connection_export       => CONNECTED_TO_buttons_external_connection_export,       --       buttons_external_connection.export
			hex_display_l_external_connection_export => CONNECTED_TO_hex_display_l_external_connection_export, -- hex_display_l_external_connection.export
			hex_display_r_external_connection_export => CONNECTED_TO_hex_display_r_external_connection_export, -- hex_display_r_external_connection.export
			leds_verdes_external_connection_export   => CONNECTED_TO_leds_verdes_external_connection_export,   --   leds_verdes_external_connection.export
			pcie_hard_ip_0_pcie_rstn_export          => CONNECTED_TO_pcie_hard_ip_0_pcie_rstn_export,          --          pcie_hard_ip_0_pcie_rstn.export
			pcie_hard_ip_0_powerdown_pll_powerdown   => CONNECTED_TO_pcie_hard_ip_0_powerdown_pll_powerdown,   --          pcie_hard_ip_0_powerdown.pll_powerdown
			pcie_hard_ip_0_powerdown_gxb_powerdown   => CONNECTED_TO_pcie_hard_ip_0_powerdown_gxb_powerdown,   --                                  .gxb_powerdown
			pcie_hard_ip_0_refclk_export             => CONNECTED_TO_pcie_hard_ip_0_refclk_export,             --             pcie_hard_ip_0_refclk.export
			pcie_hard_ip_0_rx_in_rx_datain_0         => CONNECTED_TO_pcie_hard_ip_0_rx_in_rx_datain_0,         --              pcie_hard_ip_0_rx_in.rx_datain_0
			pcie_hard_ip_0_tx_out_tx_dataout_0       => CONNECTED_TO_pcie_hard_ip_0_tx_out_tx_dataout_0,       --             pcie_hard_ip_0_tx_out.tx_dataout_0
			red_leds_external_connection_export      => CONNECTED_TO_red_leds_external_connection_export,      --      red_leds_external_connection.export
			switches_external_connection_export      => CONNECTED_TO_switches_external_connection_export       --      switches_external_connection.export
		);
