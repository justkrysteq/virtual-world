{
	description = "Virtual World";

	inputs = {
		nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
	};

	outputs = { nixpkgs, ... }:
	let
		pkgs = nixpkgs.legacyPackages.x86_64-linux;

		# Aliases
		m = pkgs.writeShellScriptBin "m" ''
			#!${pkgs.bash}/bin/bash
			make
		'';

		c = pkgs.writeShellScriptBin "c" ''
			#!${pkgs.bash}/bin/bash
			make clean
		'';

		run = pkgs.writeShellScriptBin "run" ''
			#!${pkgs.bash}/bin/bash
			./virtual-world
		'';
		
		a = pkgs.writeShellScriptBin "a" ''
			#!${pkgs.bash}/bin/bash
			if [ -f ./virtual-world ]; then
				make clean;
				make -j 12;
			else
				make -j 12;
			fi

			./virtual-world
		'';
	in
	{
		devShells.x86_64-linux.default = pkgs.mkShell {
			buildInputs = with pkgs; [
				gcc gnumake ncurses # clang-tools

				# Aliases
				m c run a
			];
		};
	};
}
