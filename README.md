# DeltaBest

A [Geode](https://geode-sdk.org/) mod for Geometry Dash that plays DELTARUNE's "Weird Route" jingle whenever you beat your personal best on a level.

## How it works

Hooks `PlayLayer::showNewBest`, which the game already calls exactly when a new best percentage is recorded, and plays a short jingle through `FMODAudioEngine`. Jingle volume is adjustable in the mod's settings.

## Setup

1. Drop your own copy of the jingle audio as `resources/weird-route.ogg` (not included in this repo — see [Audio](#audio)).
2. Set the `GEODE_SDK` environment variable to point at your local [Geode SDK](https://github.com/geode-sdk/geode) checkout.
3. Build:
   ```sh
   cmake -B build
   cmake --build build
   ```
4. The built `.geode` package will be under `build/`. Copy it into your Geode `mods/` folder, or use the [Geode CLI](https://docs.geode-sdk.org/geode-cli/) / [Dev Tools](https://docs.geode-sdk.org/mods/dev-tools/) to install it directly.

## Audio

This repo does not ship the DELTARUNE jingle — it's Toby Fox's copyrighted work, not mine to redistribute. Grab a short clip of the "Weird Route" cue yourself (an .ogg a few seconds long works best), save it as `resources/weird-route.ogg`, and build.

## License

Code in this repo is MIT licensed. See [LICENSE](LICENSE). The audio asset referenced above is NOT covered by this license and must be sourced separately by each user.
