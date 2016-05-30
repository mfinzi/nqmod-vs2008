// Defines.h
#pragma once

#ifndef DEFINES_LIST
// List of defines that are supposed to be for new additions and can be easily toggled on and off (plus they help with merging)
#define DEFINES_LIST

// New mathematical constants
// Delnar: these could be calculated at compile-time instead of needing defines, but I don't trust the VC compiler
#define M_E			2.71828182845904523536
#define fM_E		2.718281828f		//!< e (float)
#define M_SQRT2		1.41421356237309504880
#define fM_SQRT2	1.414213562f		//!< sqrt(2) (float)
#define M_SQRT3		1.73205080756887729353
#define fM_SQRT3	1.732050808f		//!< sqrt(3) (float)
#define M_LN2		0.693147180559945309417
#define fM_LN2		0.6931471806f		//!< ln(2) (float)
#define M_GLDNRT	1.61803398874989484820
#define fM_GLDNRT	1.618033989f		//!< (1 + sqrt(5))/2 (float), aka The Golden Ratio

// Technical Improvements
/// New GUID for NQMod
#define NQM_GUID
/// Enables Minidump Generation (originally for Civ4 by terkhen, ported to Civ5 by ls612)
#define NQM_MINIDUMPS
/// Can cache doubles from XML (Delnar: DatabaseUtility actually supports double-type, don't know why Firaxis didn't bother putting this in for good measure)
#define NQM_CACHE_DOUBLE
/// Enables const for functions, variables, and parameters that both allow it and are intended to be const
#define AUI_CONSTIFY
/// Replaces instances of vector loops using indeces with ones that use iterators
#define AUI_ITERATORIZE
/// Removes unused functions that simply increase file size of the DLL without providing any benefit
#define NQM_PRUNING
/// Fixes some sources for level 4 warnings
#define AUI_WARNING_FIXES
/// Changes the scopes of certain functions to fall in line with other functions of the same type (eg. CvUnit::CanFallBackFromMelee() is public instead of protected)
#define AUI_SCOPE_FIXES
/// Replaces all instances of iterators with postfix incrementors to have prefix incrementors, increasing performance
#define AUI_ITERATOR_POSTFIX_INCREMENT_OPTIMIZATIONS
/// Adds a few extra functions that can be used for 128-bit SSE types like __m128i and __m128d
#define AUI_SIMD_ADDITIONS
/// Fast comparison functions (to be used for built-in types like int, float, double, etc.)
#define NQM_FAST_COMP
/// Performance optimizations related to bit twiddling (http://www.graphics.stanford.edu/~seander/bithacks.html)
#define NQM_GAME_CORE_UTILS_OPTIMIZATIONS
/// CvWeightedVector's Top n Choices function now uses unsigned integers for indexes and choice numbers
#define AUI_WEIGHTED_VECTOR_FIX_TOP_CHOICES_USE_UNSIGNED
/// Optimizations and fixes to reduce distance check overhead
#define AUI_FIX_HEX_DISTANCE_INSTEAD_OF_PLOT_DISTANCE
/// Tweaks to make performance logs a bit more consistent and easier to read
#define AUI_PERF_LOGGING_FORMATTING_TWEAKS
/// Slightly increases stopwatch (performance counter) precision by performing the time delta subtraction bit before casting the result as a double
#define AUI_STOPWATCH_SUBTRACT_BEFORE_DELTA_CAST
/// Implements the missing iterator typedefs for BaseVector
#define AUI_FIX_FFASTVECTOR_BASEVECTOR_ITERATOR
/// Implements the missing erase(iterator) function for FFastVector
#define AUI_FIX_FFASTVECTOR_ERASE
/// Functions that called ints for variables used for indexes and choice numbers now call unsigned ints instead
#define AUI_FIX_FFASTVECTOR_USE_UNSIGNED
/// Minor optimizations to some FFastVector classes, justified by the fact that these classes are used extremely often and speed is of the essence when accessing their methods
#define AUI_FIX_FFASTVECTOR_OPTIMIZATIONS
/// Optimized parts of functions responsible for updating plot vision code
#define AUI_PLOT_VISIBILITY_OPTIMIZATIONS
/// Optimizes loops that iterate over relative coordinates to hexspace
#define AUI_HEXSPACE_DX_LOOPS
/// Fixes some misc. warnings/errors generated when code is attempted to be compiled using VC120 (it won't work because link targets are all VC90-compiled, but all other errors/warnings are legitimate)
#define AUI_VC120_FORMALITIES
/// CvUnit::canMoveOrAttackInto() no longer calls certain expensive calls twice (also improves pathfinder performance)
#define AUI_UNIT_FIX_CAN_MOVE_OR_ATTACK_INTO_NO_DUPLICATE_CALLS
/// CvUnit::canMoveInto() is optimized to not perform redundant checks for attack flag (also improves pathfinder performance)
#define AUI_UNIT_FIX_CAN_MOVE_INTO_OPTIMIZED
/// The object used to store danger values is changed to an array instead of an FFastVector
#define AUI_DANGER_PLOTS_FIX_USE_ARRAY_NOT_FFASTVECTOR
/// Units who are delayed dead will not be fetched by functions that get enemy defenders
#define AUI_PLOT_FIX_ENEMY_DEFENDER_GETTER_DOES_NOT_GET_DELAYED_DEAD
/// When the citizen manager reallocates all citizens, it no longer goes through the costly process of calculating the worst plot multiple times
#define AUI_CITIZENS_FIX_DO_REALLOCATE_CITIZENS_NO_COSTLY_PLOT_REMOVAL
/// Fixes a few possible cases of null pointer dereferences in FindTacticalTargets()
#define AUI_TACTICAL_FIX_FIND_TACTICAL_TARGETS_NULL_POINTER
/// The function that gets the amount of different trading partners a player has will now use an array instead of a vector to avoid crash possibilities
#define AUI_TRADE_FIX_GET_NUM_DIFFERENT_TRADING_PARTNERS_USES_ARRAY
/// Fixes the fact that the game's Linear Congruential RNG is set to use constants that would require a modulus of 2^31 instead of ones that need 2^32 (I couldn't introduce a modulus step because Civ5's engine really dislikes modifications to the RNG system)
#define AUI_RANDOM_FIX_CONSTANTS_SET_TO_MODULUS_2_POW_32
/// Fixes a possible crash when exiting the game caused by heap corruption when deallocating CvGameLeagues due to misuse of an FStaticVector
#define AUI_LEAGUES_FIX_POSSIBLE_DEALLOCATION_CRASH
/// Fixes a possible crash when exiting the game caused by too few items in a FStaticVector
#define AUI_TRADE_FIX_POSSIBLE_DEALLOCATION_CRASH
/// Fixes the fact that an FStaticVector type containing objects with trivial constructors (i.e. they are "Plain Old Data" = POD) is treated as the vector type wouldn't be POD (improves stability and performance)
#define AUI_TRADE_FIX_FSTATICVECTOR_CONTENTS_ARE_POD
/// Eliminates an unneccessary loop and a few more steps from the function that stores a trade route's path into the trade route's data
#define AUI_TRADE_OPTIMIZE_COPY_PATH_INTO_TRADE_CONNECTION
/// Fixes a possible crash that happens when flavors are broadcast
#define AUI_FLAVORMANAGER_FIX_POSSIBLE_CRASH_ON_FLAVOR_BROADCAST

// Fixes to game bugs and New/Tweaked gameplay aspects ported from AuI
/// Yields are cached and processed after the player's turn completes, not before the player's turn starts
#define AUI_YIELDS_APPLIED_AFTER_TURN_NOT_BEFORE
/// Removes the cap of 8 range for unit sight; this was only needed because the for() loops weren't set up properly, resulting in too many unused cycles
#define AUI_PLOT_SEE_FROM_SIGHT_NO_MAXIMUM_SIGHT_RANGE
/// When choosing the top n choices from a weighted vector, choices with weight equal to the last choice are also included
#define AUI_WEIGHTED_VECTOR_FIX_TOP_CHOICES_TIE
/// In Hotseat (and now for all multiplayer modes), wars are now declared at the beginning of the AI's turn rather than at the beginning of the human player's turn
#define AUI_DIPLOMACY_AI_FIX_WAR_DECLARATION_IN_MULTIPLAYER
/// Turn timers are paused when a player is reconnecting
#define AUI_GAME_SET_PAUSED_TURN_TIMERS_PAUSE_ON_RECONNECT
/// If the player receives a yield from a goody hut, floating text appears above the plot indicating the number and type of yields received
#define AUI_PLAYER_RECEIVE_GOODY_PLOT_MESSAGE_FOR_YIELD
/// Disables the check for whether a unit is currently embarked for triggering Denmark's UA, so the pathfinder can use it properly
#define AUI_UNIT_MOVEMENT_FIX_BAD_VIKING_DISEMBARK_PREVIEW
/// The allows water walk check is fixed to no longer trigger if water walk improvements are not built adjacent to each other
#define AUI_UNIT_MOVEMENT_FIX_BAD_ALLOWS_WATER_WALK_CHECK
/// Fixes a possible null pointer dereferences in FoundPantheon()
#define AUI_RELIGION_FIX_FOUND_PANTHEON_NULL_POINTER_DEREFERENCE
/// Changes the code that activates "We are Family" to work properly. Since achievements are disabled for modded games, this only works if the mod is turned into mock DLC
#define AUI_ACHIEVEMENT_FIX_RELIGION_WE_ARE_FAMILY_WORKING
/// Promotions that grant air combat bonuses are now allowed for units with no ability for air combat if the promotion also grants the ability for air combat
#define AUI_UNIT_FIX_ALLOW_COMBO_AIR_COMBAT_PROMOTIONS
/// Fixes radar (Delnar: first bit was covered by GJS, remaining bits are now also covered) 
#define AUI_ASTAR_FIX_RADAR
/// Fixes rarer cases of radar
#define AUI_UNIT_FIX_RADAR
/// Fixes cases of indirect radaring via ZOC.
#define AUI_UNIT_MOVEMENT_FIX_RADAR_ZOC
/// Fixes the influence cost calculator function to only enable the reuse pathfinder flag when it wouldn't result in incorrect data
#define AUI_MAP_FIX_CALCULATE_INFLUENCE_DISTANCE_REUSE_PATHFINDER
/// Fixes Iroquois' UA so friendly forest tiles will now connect with road tiles!
#define AUI_UNIT_MOVEMENT_IROQUOIS_ROAD_TRANSITION_FIX
/// Fixes base heal mod from players not actually increasing base healing
#define AUI_UNIT_FIX_BASE_HEAL_MOD
/// If a plot's feature is ignored when calculating the yield of a tile, this also extends to any yield changes based on the working city
#define AUI_PLOT_FIX_GET_YIELD_WITH_BUILD_IGNORE_FEATURE_EXTENDS_TO_CITY
/// Fixes the poor setup of calculating the potential gains of having an improvement on a plot with a certain road
#define AUI_PLOT_FIX_GET_YIELD_WITH_BUILD_IMPROVEMENT_WITH_ROUTE
/// If the plot's current route is pillaged, the extra yield from the route is no longer factored into the function
#define AUI_PLOT_FIX_IMPROVEMENT_YIELD_CHANGES_CATCH_PILLAGED_ROUTE
/// Fixes AI Shoshone Pathfinders not getting any goody hut bonuses (TODO: have AI Shoshone actually choose their goody hut bonus instead of getting a random one)
#define AUI_PLAYER_FIX_GOODY_HUT_PICKER
/// Fixes the fact that the function to get a great general stacked with the unit does not detect great admirals (for naval units)
#define AUI_UNIT_FIX_GET_STACKED_GREAT_GENERAL_WORKS_WITH_ADMIRAL
/// Fixes badly set up damage modifier checks (eg. Friendly lands modifier got applied twice to melee attackers, Friendly/Enemy territory bonus for ranged units applied based on plot target instead of unit plot)
#define AUI_UNIT_FIX_BAD_BONUS_STACKS
/// Implements the missing getter for the enemy defender based on the unit in question (rather than the player); this is important for hidden nationality units
#define AUI_PLOT_GET_VISIBLE_ENEMY_DEFENDER_TO_UNIT
/// Fixes the bug where order-specific hammer bonuses would go into overflow for an order that may not be eligible for those bonuses
#define AUI_CITY_FIX_DO_PRODUCTION_NO_OVERFLOW_EXPLOIT
#ifndef AUI_YIELDS_APPLIED_AFTER_TURN_NOT_BEFORE
/// If a city grows or starves a population, it will add any difference in food production after the change to its food supply. Among other things, this means a) the food yields earned by new citizens are evaluated just like all other yields, and b) the food consumption of the new citizen is taken into account on the turn the citizen is added
#define AUI_CITY_FIX_DO_GROWTH_USE_FOOD_AFTER_POP_CHANGE
/// Food and production earned from a newly constructed building is added into the city's food and production pools, just like how new buildings add onto all other yields the turn they are constructed
#define AUI_CITY_FIX_DO_PRODUCTION_CONSIDER_FOOD_HAMMERS_FROM_NEW_BUILDING
#endif
/// Domain modifiers to trade route yields now stack multiplicatively with other modifiers instead of additively. Among other things, this fixes Iron Curtain giving a lower-than-expected bonus to naval trade routes
#define AUI_TRADE_FIX_CONNECTION_VALUE_MULTIPLICATIVE_STACKING_DOMAIN_MODIFIERS
/// Free courthouses are no longer removed when puppeting a city
#define AUI_CITY_FIX_DO_CREATE_PUPPET_FREE_COURTHOUSES_KEPT
/// Fixes the fact that in simultaneous turns multiplayer, barbarians can spawn and then move units in the same turn.
#define AUI_GAME_FIX_MULTIPLAYER_BARBARIANS_SPAWN_AFTER_MOVING
/// Fixes the bug where a low beaker yield put into an RA would result in an artificially lower beaker reward
#define AUI_DEAL_FIX_ACCURATE_EARLYGAME_RESEARCH_AGREEMENT_YIELDS
/// Automating a unit no longer resets the turn timer (from theCAndeMan)
#define NQM_GAME_FIX_TURN_TIMER_RESET_ON_AUTOMATION
/// If multiple civs have are eligible to found the league, choose a random one instead of the one with the highest slot
#define AUI_VOTING_RANDOMIZED_LEAGUE_FOUNDER
/// Adds a few more things that are transferred to gifted units (GS beaker count, whether the unit is set up for ranged attacks, how many interceptions the unit has made) and removed some things being applied to gifted units (eg. gifted GP no longer triggers CS quests)
#define AUI_UNIT_FIX_GIFTED_UNITS_ARE_GIFTED_NOT_CLONED
/// Fixes a piece of code related to setting tiles around puppets to be worked by the puppet that not only did not work as intended, but could also have strange side-effects as well.
#define AUI_CITY_FIX_PUPPET_WORKED_PLOT_OVERRIDE
/// Units that are marked for death no longer generate a ZoC (from RushSecond)
#define AUI_UNIT_MOVEMENT_FIX_DELAYED_DEATH_UNITS_GENERATE_ZOC
/// Fixed the fact that some player-based modifiers to research costs are all only aesthetic, i.e. their only effect before would be to increase the number the UI displays for tech cost (they didn't actually modify tech cost)
#define AUI_TECH_FIX_PLAYER_BASED_RESEARCH_COST_ONLY_AESTHETIC
/// Fixed the bug where the production bonus from having a railroad connecting a city to the capital is not removed if the railroad connection is broken (credits to Wr4ith pointing this out after having researched the "weirdness" behind harbors, railroads, and the railroad bonus)
#define AUI_CITY_FIX_UPDATE_RAILROAD_CONNECTION_ALLOW_REMOVAL
/// Civilian units won't even start attempting to path to attack a tile. This should hopefully also fix the occasional problem of civilian units not wanting to move to a specific tile
#define AUI_UNIT_MISSION_FIX_CONTINUE_MISSION_CIVILIANS_DONT_ATTEMPT_ATTACK
/// Players are allowed to research if they own a city, they no longer need to found one before researching is unlocked (helps with Germany challenge on maps with CS's)
#define AUI_PLAYERTECH_FIX_CAN_RESEARCH_WITH_NO_FOUNDED_CITY

// Turn timer stuff
/// New option that allows custom turn timer settings to multiply/divide the default turn times by a certain amount instead of forcing turn times to be the custom amount
#define AUI_GAME_RELATIVE_TURN_TIMERS
/// New option that pauses the game when an active player disconnects and the game is not sequential
#define AUI_GAME_AUTOPAUSE_ON_ACTIVE_DISCONNECT_IF_NOT_SEQUENTIAL

// Deliberate AI hindrances
/// AI players will no longer spread their religion to other human players' cities
#define NQM_AI_GIMP_NO_RELIGION_SPREAD
/// AI players will no longer attempt to build any world wonders or world projects
#define NQM_AI_GIMP_NO_WORLD_WONDERS

// Observer mode fixes
/// Observers will see all resources
#define AUI_PLOT_OBSERVER_SEE_ALL_RESOURCES
/// Observers will have constant visibility over all plots
#define AUI_PLOT_OBSERVER_SEE_ALL_PLOTS
/// Observers are set to have met every team in the game
#define AUI_GAME_OBSERVER_MEET_ALL_TEAMS
/// Natural wonder pop-ups do not trigger for observers
#define AUI_PLOT_OBSERVER_NO_NW_POPUPS
/// Observers can now open the city screen as if they had spies in every city
#define AUI_GAME_OBSERVER_CAN_OPEN_CITIES
/// All cities are set to be revealed to observers
#define AUI_CITY_OBSERVER_REVEALS_ALL_CITIES

// Altered score calculations as an option toggleable in-game
#define NQM_OPTIONAL_SCORING_TWEAKS

// New hybrid mode
/// When in hybrid mode, players who are not at war with each other have their turns happen simultaneously, thus speeding games up significantly
//#define AUI_GAME_BETTER_HYBRID_MODE
#ifdef AUI_GAME_BETTER_HYBRID_MODE
/// Turn lengths are determined for each player at the beginning of the turn and cached, instead of having turn lengths be a global variable whose value can change mid-turn
#define AUI_GAME_PLAYER_BASED_TURN_LENGTH
#endif

// Pathfinder (A*) optimizations, tweaks, and fixes
/// A* functions no longer run the canEnterTerrain() functions during validation (it should normally be run once and cached, but Firaxis did a bunch of stupids)
#define AUI_ASTAR_FIX_CAN_ENTER_TERRAIN_NO_DUPLICATE_CALLS
/// Moves the check for whether a node has no parent to the beginning of PathValid() (originally from Community Patch)
#define AUI_ASTAR_FIX_PARENT_NODE_ALWAYS_VALID_OPTIMIZATION
/// Reorders some checks to make sure ones that process faster get executed first (if they fail, then the function skips checking the slower ones)
#define AUI_ASTAR_FIX_FASTER_CHECKS
/// Calculates the neighbors of a tile on pathfinder initialization instead of at path construction (originally from Community Patch)
#define AUI_ASTAR_PRECALCULATE_NEIGHBORS_ON_INITIALIZE
/// Minor A* optimizations
#define AUI_ASTAR_MINOR_OPTIMIZATION
/// Pathfinders now have a built-in turn limiter that invalidates too long paths they are being built instead of after the best path has been calculated (also enables calculating turns to a target from a plot other than the unit's current plot)
#define AUI_ASTAR_TURN_LIMITER
/// Gets the last node before the parent (used for planning melee attacks to know where they'd attack from)
#define AUI_ASTAR_GET_PENULTIMATE_NODE
/// Fixes possible null pointer dereferences in A*
#define AUI_ASTAR_FIX_POSSIBLE_NULL_POINTERS
/// Human-controlled missionaries and units will still want to avoid undesirable tiles a bit when planning paths, though not to the full extent that an AI-controlled unit would (parameter value is the extra "cost" weight added)
#define AUI_ASTAR_HUMAN_UNITS_GET_DIMINISHED_AVOID_WEIGHT (1)
/// Pointers to the plot representing each A* node are stored in the A* node in question
#define AUI_ASTAR_CACHE_PLOTS_AT_NODES
/// Adds a new function that is a middle-of-the-road fix for allowing the functions to take account of roads and railroads without calling pathfinder too often
#define AUI_ASTAR_TWEAKED_OPTIMIZED_BUT_CAN_STILL_USE_ROADS
/// The danger of a tile will only be considered when checking path nodes, not when checking the destination (stops units from freezing in panic)
#define AUI_ASTAR_FIX_CONSIDER_DANGER_ONLY_PATH
/// The path's destination's danger value will be considered instead of the original plot's danger value, otherwise we're just immobilizing AI units (oddly enough, the Civ4 algorithm is fine, only the Civ5 ones needed to be fixed)
#define AUI_ASTAR_FIX_CONSIDER_DANGER_USES_TO_PLOT_NOT_FROM_PLOT
#ifdef AUI_ASTAR_FIX_CONSIDER_DANGER_USES_TO_PLOT_NOT_FROM_PLOT
/// If the pathfinder does not ignore danger, the plot we're moving from must pass the danger check before we consider the destination plot's danger
#define AUI_ASTAR_FIX_CONSIDER_DANGER_ONLY_POSITIVE_DANGER_DELTA
#endif
/// If the pathfinder does not ignore danger, use the unit's combat strength times this value as the danger limit instead of 0 (important for combat units)
#define AUI_ASTAR_FIX_CONSIDER_DANGER_USES_COMBAT_STRENGTH (6)
/// AI-controlled units no longer ignore all paths with peaks; since the peak plots are checked anyway for whether or not a unit can enter them, this check is pointless
#define AUI_ASTAR_FIX_PATH_VALID_PATH_PEAKS_FOR_NONHUMAN
/// Mountain tiles are no longer automatically marked as invalid steps
#define AUI_ASTAR_FIX_STEP_VALID_CONSIDERS_MOUNTAINS
#ifdef AUI_PLOT_GET_VISIBLE_ENEMY_DEFENDER_TO_UNIT
/// When a unit will attack onto a plot, it will try to minimize the damage it would receive from each plot candidate. If it will always die, it will instead maximize dealt damage.
#define AUI_ASTAR_CONSIDER_DAMAGE_WHEN_ATTACKING
#endif
#ifndef AUI_ASTAR_CONSIDER_DAMAGE_WHEN_ATTACKING // Already handled by the other algorithm
/// When a unit will attack onto a plot, river crossings are avoided whenever possible
#define AUI_ASTAR_AVOID_RIVER_CROSSING_WHEN_ATTACKING
#endif
/// Units without a defense bonus still consider a tile's defense penalties when pathfinding
#define AUI_ASTAR_FIX_DEFENSE_PENALTIES_CONSIDERED_FOR_UNITS_WITHOUT_DEFENSE_BONUS
/// Fixes a nonsense territory check in the Ignore Units pathfinder (can this unit enter territory owned by this unit's team?) by replacing it with one that actually makes sense (can this unit enter territory of the player who owns the target plot?)
#define AUI_ASTAR_FIX_IGNORE_UNITS_PATHFINDER_TERRITORY_CHECK
/// In addition to the movement cost from features on a tile, the route recommender will now also consider the movement cost of moving onto a tile with hills
#define AUI_ASTAR_FIX_BUILD_ROUTE_COST_CONSIDER_HILLS_MOVEMENT
/// When a unit is set to auto-explore, it will consider how many tiles are revealed past the 1st ring as well
#define AUI_ASTAR_FIX_MAXIMIZE_EXPLORE_CONSIDER_2ND_RING_NONREVEALED
/// Units that are on automated explore will prefer to visit tiles that have a higher "see from" stat instead of just hills (eg. helps with Carthage)
#define AUI_ASTAR_FIX_MAXIMIZE_EXPLORE_UNHARDCODE_HILL_PREFERENCE
/// Tweaks the amount of extra cost a tile receives for each new tile it doesn't reveal
#define AUI_ASTAR_TWEAKED_PATH_EXPLORE_NON_REVEAL_WEIGHT (50)
/// Units with the Explore UnitAIType will always move to maximize exploration
#define AUI_ASTAR_EXPLORE_UNITAITYPE_ALWAYS_MAXIMIZES_EXPLORE

// Binomial RNG Stuff (Delnar: the binomial RNG generates numbers in a binomial distribution instead of a flat one like the regular RNG)
/// Enables the Binomial Random Number Generator (originally from Artificial Unintelligence)
#define AUI_BINOM_RNG
#ifdef AUI_BINOM_RNG
/// Generated ridges use the binomial RNG for directional bias strength and ridge weakness
#define AUI_FRACTAL_RIDGE_USE_BINOM_RNG
/// When modifying a personality value (eg. Boldness, Wonder Competitiveness), the AI will use the binomial RNG for a normal distribution instead of a flat one
#define AUI_DIPLOMACY_GET_RANDOM_PERSONALITY_WEIGHT_USES_BINOM_RNG
/// When adding or subtracting flavor value, the binomial RNG is used to generate a normal distribution instead of a flat one
#define AUI_FLAVOR_MANAGER_GET_ADJUSTED_VALUE_USES_BINOM_RNG
#endif

// AI fixes that significantly affect MP
/// Disables the active grand strategy for AIs operating behind human players, the primary effect of which is that puppets don't do as much weird stuff
#define AUI_GS_FIX_NO_ACTIVE_GS_FOR_HUMANS
/// Instead of ignoring all military training buildings (eg. stables, kreposts, etc.), puppets will instead nullify the Military Training and Naval flavors
#define AUI_CITYSTRATEGY_FIX_CHOOSE_PRODUCTION_PUPPETS_NULLIFY_BARRACKS
/// Scales the GetLastTurnWorkerDisbanded() computation to game speed
#define AUI_CITYSTRATEGY_FIX_TILE_IMPROVERS_LAST_DISBAND_WORKER_TURN_SCALE
/// If a player does not have any non-scouting military units, the "enough workers" city strategy is triggered and the "want workers" and "need workers" city strategies always return false
#define AUI_CITYSTRATEGY_DONT_EMPHASIZE_WORKERS_IF_NO_MILITARY
/// Fixes the "zeroed out flavor" check to still accept 0 as a possible flavor value, but not accept negative values
#define AUI_FLAVOR_MANAGER_FIX_RANDOMIZE_WEIGHTS_ZEROED_OUT_FLAVOR
/// Fixes the function messing up and returning the wrong adjustment when the value to be added is actually negative (eg. for minor civs)
#define AUI_FLAVOR_MANAGER_FIX_GET_ADJUSTED_VALUE_NEGATIVE_PLUSMINUS
/// If the first adjusted value is out of bounds, keep rerolling with the amount with which it is out of bounds until we remain in bounds
#define AUI_FLAVOR_MANAGER_GET_ADJUSTED_VALUE_USE_REROLLS
/// Plots that are under immediate threat by an even number of units will properly return that the plot is under immediate threat
#define AUI_DANGER_PLOTS_FIX_ADD_DANGER_WITHIN_ONE_MOVE
/// The ignore visibility switch for DangerPlots also works on the plot visibility check
#define AUI_DANGER_PLOTS_FIX_SHOULD_IGNORE_UNIT_IGNORE_VISIBILITY_PLOT
/// Minors will always "see" units of major civs in tiles (value) away from their city (since minors don't scout) when plotting danger values (stops excessive worker stealing)
#define AUI_DANGER_PLOTS_SHOULD_IGNORE_UNIT_MINORS_SEE_MAJORS (5)
/// Minors will ignore all units of players who are not at war with them
#define AUI_DANGER_PLOTS_FIX_IS_DANGER_BY_RELATIONSHIP_ZERO_MINORS_IGNORE_ALL_NONWARRED
/// Minors will assume trespassing units are there for war
#define AUI_DANGER_PLOTS_IS_DANGER_BY_RELATIONSHIP_ZERO_MINORS_DO_NOT_IGNORE_TRESSPASSERS
/// Fixes bad code for visible barbarian units adding to "barbarian threat" value (affects CS)
#define AUI_MILITARY_FIX_BARBARIAN_THREAT
/// If the AI's religion now unlocks multiple faith buildings, AI can now purchase all of them
#define AUI_RELIGION_FIX_MULTIPLE_FAITH_BUILDINGS
/// Fixes the check for whether ranged damage would be more than heal rate to use >= instead of >, adds a flat value to total damage at start (both make up for randomness), and treats cities as an expected damage source instead of a flat "yes"
#define AUI_UNIT_FIX_UNDER_ENEMY_RANGED_ATTACK_HEALRATE (1)
/// The AI will consider promises it made not to convert cities of a player when choosing a prophet conversion target
#define AUI_RELIGION_FIX_CHOOSE_PROPHET_CONVERSION_CITY_HONOR_NONCONVERT_PROMISE

// Flavor system changes (affect CS build queue and puppet build queue)
/// Free buildings and units that a building would generate are factored into the flavor
#define AUI_BUILDING_PRODUCTION_AI_CONSIDER_FREE_STUFF
/// Policies can now alter the flavors of certain buildingclasses (disabled for now because it crashes at initialization)
//#define AUI_POLICY_BUILDING_CLASS_FLAVOR_MODIFIERS
/// Beliefs can now alter the flavors of certain buildingclasses
//#define AUI_BELIEF_BUILDING_CLASS_FLAVOR_MODIFIERS

// Citizen Management Fixes
/// Extra food value assigned to specialists for half food consumption now depends on the XML value for citizen food consumption (instead of assuming the default value)
#define AUI_CITIZENS_FIX_SPECIALIST_VALUE_HALF_FOOD_CONSUMPTION
/// Replaces the rudimentary specialist-plot check with a plot vs. default citizen value check
#define AUI_CITIZENS_IS_PLOT_BETTER_THAN_DEFAULT_SPECIALIST
/// The value of excess food is multiplied by the city's growth modifiers
#define AUI_CITIZENS_GET_VALUE_CONSIDER_GROWTH_MODIFIERS
/// If a tile would provide enough food to generate excess food, the excess amount has its value halved as if the city was already generating enough food
#define AUI_CITIZENS_GET_VALUE_SPLIT_EXCESS_FOOD_MUTLIPLIER
/// If a city is using excess food for production, change the value of food yields accordingly (eg. city cannot starve, food is not 1:1 with production)
#define AUI_CITIZENS_GET_VALUE_ALTER_FOOD_VALUE_IF_FOOD_PRODUCTION
/// If a city has any modifiers on certain yield incomes, this modification is applied to the value of those yields as well (eg. +25% gold increases gold yield value by 25%)
#define AUI_CITIZENS_GET_VALUE_CONSIDER_YIELD_RATE_MODIFIERS
/// Games where happiness is disabled no longer cause the citizen manager to always ignore the avoid growth checkbox
#define AUI_CITIZENS_FIX_AVOID_GROWTH_FLAG_NOT_IGNORED_IF_NO_HAPPINESS
#ifndef AUI_CITIZENS_GET_VALUE_CONSIDER_GROWTH_MODIFIERS // The define below is only useful if growth modifiers aren't considered
/// The citizen manager only forces avoid growth from low happiness when growing in the city would lower the player's happiness. Also, avoid growth is enabled for cities that would grow next turn to make the empire unhappy.
#define AUI_CITIZENS_FIX_FORCED_AVOID_GROWTH_ONLY_WHEN_GROWING_LOWERS_HAPPINESS
#endif
/// When comparing whether a specialist is better than an unemployed citizen, regular value evaluation is used
#define AUI_CITIZENS_IS_BETTER_THAN_DEFAULT_SPECIALIST_USE_REGULAR_VALUES
/// The value of food is now properly increased if the city is on food focus with the avoid growth flag set
#define AUI_CITIZENS_FIX_GET_VALUE_FOOD_YIELD_VALUE_WHEN_STARVATION_WITH_AVOID_GROWTH
/// Instead of cities with 4 or less population and set to either no focus or partial food focus multiplying food value by 4, all cities with 4 or less population will want at least 2 food just like ones set to no focus or partial/full food focus
#define AUI_CITIZENS_LOW_POPULATION_CITIES_USE_2MIN_NOT_4X_FOOD
/// If a city is set to avoid growth, it will assign a value of 1 to excess food instead of 0. While it's still much less than a Gold yield, it at least makes 3 food tiles more preferable to 2 food tiles even when avoiding growth
#define AUI_CITIZENS_AVOID_GROWTH_STILL_VALUES_EXCESS_FOOD
/// Unhardcodes the value assigned to specialists for happiness (flat value is the base multiplier for value of a single happiness point before modifications)
#define AUI_CITIZENS_UNHARDCODE_SPECIALIST_VALUE_HAPPINESS (8)
#ifdef AUI_CITIZENS_UNHARDCODE_SPECIALIST_VALUE_HAPPINESS
/// Citizen Manager considers the effect of half specialist unhappiness on other yields
#define AUI_CITIZENS_CONSIDER_HAPPINESS_VALUE_ON_OTHER_YIELDS
#endif
/// If the player has negative gold income and would lose science as a result, gold yield is scored as if it were science yield
#define AUI_CITIZENS_GOLD_YIELD_COUNTS_AS_SCIENCE_WHEN_IN_DEFICIT
/// The function that removes the worst specialist from their slot actually removes the worst one instead of just the first specialist encountered
#define AUI_CITIZENS_FIX_REMOVE_WORST_SPECIALIST_ACTUALLY_REMOVES_WORST
/// Adds a self-consistency check function to citizen manager, which constantly shifts the worst scoring citizen to the best scoring spot until it's not actually shifting the citizen or it keeps shifting back and forth between the same spots.
#define AUI_CITIZENS_SELF_CONSISTENCY_CHECK (1) // This is the score difference threshold below which the SC loop will terminate
#ifdef AUI_CITIZENS_SELF_CONSISTENCY_CHECK
/// Reallocate citizens runs a self-consistency check after it reallocates everyone
#define AUI_CITIZENS_REALLOCATE_CITIZENS_USES_SELF_CONSISTENCY
#ifdef AUI_YIELDS_APPLIED_AFTER_TURN_NOT_BEFORE
/// After reallocating citizens in all cities at the beginning of the turn, a self-consistency check is run for all cities (so 
#define AUI_PLAYER_SELF_CONSISTENCY_SWEEP_AFTER_INITIAL_REALLOCATE
#endif
#endif
/// If a city's religion has the Guruship belief, the citizen manager will account for the extra production gained from the first citizen slot
#define AUI_CITIZENS_GET_SPECIALIST_VALUE_ACCOUNT_FOR_GURUSHIP
/// Puppets not set to soft or hard avoid growth will still want at least 1 excess food (Gold Focus would disallow this). This removes need for some code that helps avoid starvation but could be abused by a human, so this code was disabled.
#define AUI_CITIZENS_PUPPET_STILL_WANTS_GROWTH
/// Puppeting or annexing a city will immediately reallocate citizens and set focuses when the order is given. It also means players don't have to manually remove Gold focus when unpuppeting a city.
#define AUI_CITIZENS_PUPPET_AND_ANNEX_REALLOCATES_CITIZENS

// City Governor Stuff
/// Fixes various possible bugs by replacing std::vector with FFastVector as the list type and relying on push_back() and clear() instead of trying to handle the vector as a matrix
#define AUI_CITY_FIX_GET_NEXT_BUYABLE_PLOT_USE_FFASTVECTOR
/// Replaces the "lower influence cost by 1 if near NW or resource" code with code that lowers the influence cost of plots that are between resources or natural wonders and the closest owned plot of the city
#define AUI_CITY_GET_BUYABLE_PLOT_LIST_RESOURCE_NW_OSMOSIS
/// Weights the yield contribution to a plot's influence cost by the value of the yield to citizen automation.
#define AUI_CITY_GET_BUYABLE_PLOT_LIST_WEIGHTED_YIELDS
#if defined(AUI_CITY_GET_BUYABLE_PLOT_LIST_RESOURCE_NW_OSMOSIS) || defined(AUI_CITY_GET_BUYABLE_PLOT_LIST_WEIGHTED_YIELDS)
/// City focus is considered when the city governor weighs the values of certain yields over others
#define AUI_CITY_GET_BUYABLE_PLOT_LIST_CONSIDER_CITY_FOCUS
#endif
/// Actually makes passive acquisition of tiles not adjacent to an already owned tile impossible
#define AUI_CITY_GET_BUYABLE_PLOT_LIST_ACTUALLY_IMPOSSIBLE_IF_NOT_ADJACENT_OWNED
/// Delnar: Moved Fruitstrike's code to prioritize plots with the lowest gold purchasing cost in the case of ties into the end of GetBuyablePlotList() so that plots will still be randomly decided if their gold purchasing costs are the same (instead of prioritizing Northeastern plots)
#define NQM_CITY_GET_NEXT_BUYABLE_PLOT_MOVE_GOLD_PURCHASE_COST_PRIORITY_TO_GET_BUYABLE_PLOT_LIST

// AI/Automated Worker fixes
/// AI/Automated Inca workers know that there is no maintenance on hills, so routines are adjusted as a result
#define AUI_WORKER_INCA_HILLS
/// AI/Automated workers do not care about the build time or cost of scrubbing fallout
#define AUI_WORKER_FIX_FALLOUT
/// Divides score for improvement if built for a puppeted city
#define AUI_WORKER_SCORE_PLOT_REDUCED_PUPPET_SCORE (2)
/// No longer artificially increases the score for plots owned by the player's capitol or an original capitol city
#define AUI_WORKER_SCORE_PLOT_NO_CAPITOL_FAVORING
/// Multiplies score for improvement if built on a plot that is either already worked or would be worked by the owning city
#define AUI_WORKER_SCORE_PLOT_MULTIPLY_SCORE_IF_WOULD_WORK (2)
/// Returns score of 0 for improvement if built for a city being razed
#define AUI_WORKER_SCORE_PLOT_NO_SCORE_FROM_RAZE
/// If building an improvement also generates flat hammers, consider the effect as flat +parameter hammer yield
#define AUI_WORKER_SCORE_PLOT_CHOP (0.5)
/// Removes the bias to chop forests after optics (since it doesn't actually offer a gameplay improvement)
#define AUI_WORKER_NO_CHOP_BIAS
/// Faith now affects tile evaluation for workers, it pulls from culture multiplier though
#define AUI_WORKER_EVALUATE_FAITH
/// AI/Automated workers value strategic resources that a player has none of higher than strategic resources that the player has used all of
#define AUI_WORKER_TWEAKED_DONT_HAVE_MULTIPLIER (6)
/// Combat workers will increase the maximum allowed plot danger value to their current strength times this value
#define AUI_WORKER_SHOULD_BUILDER_CONSIDER_PLOT_MAXIMUM_DANGER_BASED_ON_UNIT_STRENGTH (6)
/// FindTurnsAway() no longer returns raw distance, parameter dictates whether we're reusing paths and ignoring units (fast but rough) or not (slow but accurate)
#define AUI_WORKER_FIND_TURNS_AWAY_USES_PATHFINDER (true)
#ifdef AUI_PLOT_CALCULATE_STRATEGIC_VALUE
/// AddImprovingPlotsDirective() now processes improvement defense rate
#define AUI_WORKER_ADD_IMPROVING_PLOTS_DIRECTIVE_DEFENSIVES
#endif
/// Shifts the check for whether there already is someone building something on the plot to the necessary AddDirectives() functions (so collaborative building is possible)
#define AUI_WORKER_FIX_SHOULD_BUILDER_CONSIDER_PLOT_EXISTING_BUILD_MISSIONS_SHIFT
/// New function that is called by AI/Automated workers to construct non-road improvements in a minor's territory (eg. for Portugal)
#define AUI_WORKER_ADD_IMPROVING_MINOR_PLOTS_DIRECTIVES
/// Multiplies the weight of unowned luxury resources for plot directives depending on the empire's happiness (value is the multiplier at 0 happiness)
#define AUI_WORKER_GET_RESOURCE_WEIGHT_INCREASE_UNOWNED_LUXURY_WEIGHT (2.0)
/// Consider extra sources of happiness once a resource is obtained (eg. extra happiness from luxury resources via policy, extra happiness from resource variety)
#define AUI_WORKER_GET_RESOURCE_WEIGHT_CONSIDER_EXTRAS_FOR_HAPPINESS_FROM_RESOURCE
/// Removes the isAdjacent check for whether a work boat can access an area different from its current one (pathfinder takes care of bad cases anyway, it's just a bit slower)
#define AUI_WORKER_FIX_SHOULD_CONSIDER_PLOT_WORK_BOATS_CONSIDER_ALL_SEA_PLOTS
/// Only disregard an impassable plot if the unit cannot enter impassable plots
#define AUI_WORKER_FIX_SHOULD_CONSIDER_PLOT_FLYING_WORKER_DISREGARDS_PEAKS
/// Added some extra checks for Celts so that 1) they will improve forests when there would still be enough unimproved ones remaining to give the same faith bonus and 2) they will not improve luxury resources on forests if they do not get any use out of them and would lower faith
#define AUI_WORKER_FIX_CELTIC_IMPROVE_UNIMPROVED_FORESTS
/// AI/Automated workers will no longer automatically continue building the improvement they are currently building if the tile they are on is in danger (instead of having this behavior trigger in CvHomelandAI)
#define AUI_WORKER_EVALUATE_WORKER_RETREAT_AND_BUILD
/// AI/Automated workers will now consider any modifiers the player has to road maintenance when calculating how much profit the road earns
#define AUI_WORKER_FIX_CONNECT_CITIES_TO_CAPITOL_CONSIDER_MAINTENANCE_MODIFIERS
/// No longer requires that an improvement enable use of a bonus resource, since the projected plot yields will be higher from unlocking the resource anyway
#define AUI_WORKER_FIX_IMPROVING_PLOTS_DIRECTIVE_DONT_REQUIRE_BONUS_RESOURCE_UNLOCKER
#ifdef AUI_PLAYER_CACHE_UNIQUE_IMPROVEMENTS
/// Unhardcodes the fact that the AI will not remove features that are needed to construct a civ's unique improvement
#define AUI_WORKER_UNHARDCODE_NO_REMOVE_FEATURE_THAT_IS_REQUIRED_FOR_UNIQUE_IMPROVEMENT
#endif

// HomelandAI fixes; used by automated workers/scouts and extensively by CS
/// Disables the code that would start fortifying scouts if recon state was set as "enough"
#define AUI_HOMELAND_ALWAYS_MOVE_SCOUTS
/// Tweaks the algorithm for Plot Heal Moves to keep March promotions in mind and make sure we don't overheal if we're under threat
#define AUI_HOMELAND_TWEAKED_HEAL_MOVES
/// Changes the AcceptableDanger value in PlotDangerMoves to be a function of the unit's current HP percent
#define AUI_HOMELAND_TWEAKED_ACCEPTABLE_DANGER (1.0)
/// When finding patrol targets for civilian units, subtract off danger value from plot score
#define AUI_HOMELAND_TWEAKED_FIND_PATROL_TARGET_CIVILIAN_NO_DANGER
/// Border plots, plots containing routes, and plots containing civilians are preferred over others when patrolling
#define AUI_HOMELAND_FIND_PATROL_TARGET_DESIRES_BORDER_AND_ROUTE_AND_CIVILIAN_GUARD
/// Disbanding explorers now uses the scrap() function instead of the kill() function
#define AUI_HOMELAND_FIX_EXECUTE_EXPLORER_MOVES_DISBAND
/// Stops the AI from suiciding units by embarking them onto tiles that can be attacked
#define AUI_HOMELAND_FIX_EXECUTE_MOVES_TO_SAFEST_PLOT_NO_EMBARK_SUICIDE
/// If an AI/automated worker can still move after it has reached its target, allow it to queue up a build order
#define AUI_HOMELAND_FIX_EXECUTE_WORKER_MOVE_MOVE_AND_BUILD
/// AI/Automated explorers now move after popping goody huts
#define AUI_HOMELAND_FIX_EXECUTE_EXPLORER_MOVES_MOVE_AFTER_GOODY
/// Uses the unit's in-game movement range for plot search heuristic instead of relying on the unit's info's pre-determined movement range
#define AUI_HOMELAND_FIX_EXECUTE_MOVES_TO_SAFEST_PLOT_USE_GAME_MOVEMENT_RANGE
/// Civilian units execute moves to safety instead of patrolling
#define AUI_HOMELAND_FIND_PATROL_MOVES_CIVILIANS_PATROL_TO_SAFETY
/// After moving workers around, the AI will move combat units around to guard those workers. Not ideal because AI will still not send workers to dangerous tiles even if they'd have a protector there, but better than nothing.
#define AUI_HOMELAND_PLOT_WORKER_MOVES_ALSO_PLOTS_WORKER_DEFENSE

// Voting/League AI Stuff for when a player is defeated but their AI can still vote on proposals
/// When voting for a player, the AI will now adjust for the fact that the voting system is First-Past-The-Post (so it will try to vote against players as well)
#define AUI_VOTING_SCORE_VOTING_CHOICE_PLAYER_ADJUST_FOR_FPTP
/// Uses a different algorithm for scoring voting on world ideology
#define AUI_VOTING_TWEAKED_WORLD_IDEOLOGY
/// Uses a different algorithm for scoring voting on world religion
#define AUI_VOTING_TWEAKED_WORLD_RELIGION
/// Alters some of the algorithms and values used for scoring a proposal overall (instead of just its effects), primarily based on diplomatic relations with the proposer
#define AUI_VOTING_TWEAKED_PROPOSAL_SCORING

// Start Positioner Fixes (for WorldBuilder Maps and maps not randomly generated but with random starting locations)
/// Civilizations that are marked as coastal get the same coastal bias as maritime city-states
#define AUI_STARTPOSITIONER_COASTAL_CIV_WATER_BIAS
/// When calculating the founding value of a tile, tailor the SiteEvaluation function to the current player instead of the first one
#define AUI_STARTPOSITIONER_FLAVORED_STARTS

// GlobalDefines (GD) wrappers
// INT
#define GD_INT_DECL(name)       int m_i##name
#define GD_INT_DEF(name)        inline int get##name() { return m_i##name; }
#define GD_INT_INIT(name, def)  m_i##name(def)
#define GD_INT_CACHE(name)      m_i##name = getDefineINT(#name)
#define GD_INT_GET(name)        GC.get##name()
// FLOAT
#define GD_FLOAT_DECL(name)       float m_f##name
#define GD_FLOAT_DEF(name)        inline float get##name() { return m_f##name; }
#define GD_FLOAT_INIT(name, def)  m_f##name(def)
#define GD_FLOAT_CACHE(name)      m_f##name = getDefineFLOAT(#name)
#define GD_FLOAT_GET(name)        GC.get##name()
// DOUBLE (high precision, but much slower than float)
#ifdef NQM_CACHE_DOUBLE
#define GD_DOUBLE_DECL(name)       double m_d##name
#define GD_DOUBLE_DEF(name)        inline double get##name() { return m_d##name; }
#define GD_DOUBLE_INIT(name, def)  m_d##name(def)
#define GD_DOUBLE_CACHE(name)      m_d##name = getDefineDOUBLE(#name)
#define GD_DOUBLE_GET(name)        GC.get##name()
#endif

#endif