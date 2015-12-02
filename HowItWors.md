# Introduction #

Implementation details

# Components #

  * pplication Launcher
  * urrent Generation
  * ext Generation
  * eneration counter
  * volution Job
  * ife Field Form

# Relations #

  * pplication launcher knows about:
    * ifeField - it needs to show it
    * volution Job - it needs to start it
  * ife Field Form knows about:
    * ext and Current Generations - it needs to render them
    * eneration Counter - it needs to show it
  * volution Job knows about:
    * ext and Current Generations - it needs to render them
    * eneration Counter - it needs to show it


# Flow Implementation #

  1. On application launch
    1. reates empty generation and buffered generation
    1. andomly sets seeds on current generation
    1. alculates and fills next generation
    1. enders current generation on Life Form
    1. hows enabled buttons to reset and start

  1. On clicking reset
    1. andomly sets seeds on current generation
    1. alculates and fills next generation
    1. enders generation on Life Form
    1. hows enabled buttons to reset and start

  1. On clicking start
    1. Launches timer
    1. On each timer cycle, timer:
      1. opies next generation into current
      1. alculates and fills next generation
      1. enders current generation on Life Form

  1. Updates generation counter