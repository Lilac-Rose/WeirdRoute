# Weird Route

A [Geode](https://geode-sdk.org/) mod for Geometry Dash. Pass your personal best on a level and it plays DELTARUNE's "Weird Route" jingle, right as you cross it.

## How it works

It hooks `PlayLayer::updateProgressbar`, which runs every frame during gameplay, and compares your live percent against the level's saved best (`GJGameLevel::m_normalPercent`). As soon as you pass it, the jingle plays through `FMODAudioEngine`. Jingle volume can be adjusted in the mod's settings.

## Install

Grab the `.geode` file from the [latest release](https://github.com/Lilac-Rose/DeltaBest/releases/latest) and drop it in your Geode `mods` folder. That's it.

## Building from source

Only needed if you're changing the code.

1. Set the `GEODE_SDK` environment variable to point at your [Geode SDK](https://github.com/geode-sdk/geode) checkout.
2. Build:
   ```sh
   cmake -B build
   cmake --build build
   ```
   or with the [Geode CLI](https://docs.geode-sdk.org/geode-cli/):
   ```sh
   geode build
   ```
3. Grab the `.geode` file from the build directory and drop it in your Geode `mods` folder (or let `geode build` install it for you if you've got a profile set up).

## Credits

"Weird Route" jingle from DELTARUNE, made by Toby Fox. All rights to the audio are his.

## License

Code here is MIT licensed, see [LICENSE](LICENSE). The jingle is not covered by that license.
