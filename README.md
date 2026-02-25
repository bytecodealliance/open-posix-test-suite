<div align="center">
  <h1><code>open-posix-test-suite</code></h1>

<strong>A <a href="https://bytecodealliance.org/">Bytecode Alliance</a> hosted project</strong>

  <p>
    <strong>A fork of the <a href="ttps://posixtest.sourceforge.net/">Open POSIX Test Suite</a> for <code><a href="https://github.com/WebAssembly/wasi-libc">wasi-libc</a></code></strong>
  </p>
</div>

## Open POSIX* Test Suite Overview

The POSIX Test Suite is an open source test suite with the goal of
performing conformance, functional, and stress testing of the IEEE
1003.1-2001 System Interfaces specification in a manner that is
agnostic to any given implementation.

This fork of the Open POSIX Test Suite is maintained in aid of testing [`wasi-libc`](https://github.com/WebAssembly/wasi-libc).

All code is distributed under the GNU General Public License v2.  A
copy of this license is contained in the COPYING file.

This document gives a brief overview of the test suite, including its
design goals, implementation, and how to contribute.  Within these
sections, we describe where to find more detailed information.

## Design Goals

This project was created with the following design goals:
- Enable assertion based traceability for conformance testing of POSIX
  specifications.  We wanted to capture enough data to make deterministic
  statements about our coverage of the POSIX specification.

- Give the ability to send test case source to bug reports to appropriate 
  open source projects when our test cases revealed bugs in those projects.
  (Meaning we wanted fairly simple, self-contained test cases which
  illuminated a single failure.)

- Make it easy for test cases to be contributed.

## Implementation

This project will cover conformance, functional, stress, performance,
and speculative testing.  Conformance, functional, and stress tests are
the only tests formally documented and enabled by our framework, with our 
focus mainly on conformance; however, the other types of testing will be 
added as the need arises.

For more information on these types of testing, under 'Documenation' see:

- [HOWTO_ConformanceTest](https://github.com/bytecodealliance/open-posix-test-suite/blob/main/Documentation/HOWTO_ConformanceTest): info on creation and structure of conformance tests
- [HOWTO_FunctionalStressTest](https://github.com/bytecodealliance/open-posix-test-suite/blob/main/Documentation/HOWTO_FunctionalStressTest): info on creation and structure of functional and stress tests

For additional information on how to build and run the tests in this
suite, see [wasi-libc](https://github.com/WebAssembly/wasi-libc).


## Developer Docs & Resources

The following files give developers information on how to write test
cases for the project (under Documentation):
- [HOWTO_Assertions](https://github.com/bytecodealliance/open-posix-test-suite/blob/main/Documentation/HOWTO_Assertions): describes format of the assertions files used to map test case descriptions to test cases
- [HOWTO_BoundaryTest](https://github.com/bytecodealliance/open-posix-test-suite/blob/main/Documentation/HOWTO_BoundaryTest): information about testing boundary conditions
- [HOWTO_CodingGuidelines](https://github.com/bytecodealliance/open-posix-test-suite/blob/main/Documentation/HOWTO_CodingGuidelines): describes coding guidelines for this project
- [HOWTO_Coverage](https://github.com/bytecodealliance/open-posix-test-suite/blob/main/Documentation/HOWTO_Coverage): describes format of COVERAGE.<area> files
- [HOWTO_DefinitionsTest](https://github.com/bytecodealliance/open-posix-test-suite/blob/main/Documentation/HOWTO_DefinitionsTest): ideas behind testing POSIX header files
- [HOWTO_ResultCodes](https://github.com/bytecodealliance/open-posix-test-suite/blob/main/Documentation/HOWTO_ResultCodes): standardized return codes for tests

## Disclaimer

The Open POSIX Test Suite is not affiliated with the IEEE or The Open Group.

--------

* POSIX (R) is a registered trademark of the IEEE
