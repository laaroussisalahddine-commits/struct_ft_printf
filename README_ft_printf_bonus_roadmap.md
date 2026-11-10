# ft_printf Bonus — Logic Building Roadmap

> **Goal:** Learn enough C formatting logic to implement the **42 `ft_printf` bonus independently**, without using a `struct` during training.

This is a **practice roadmap**, not a complete solution. Each mini-program builds one skill; the final challenge is to design and implement your own `ft_printf` bonus while keeping your mandatory version working.

## Training rules

- **No `struct`** in the mini-programs. Use ordinary variables and function parameters to understand the data flow.
- **Try first.** Predict the output, write the algorithm, then code it. Ask for hints before asking for a solution.
- **One exercise at a time.** Do not move forward until the current exercise works on normal and edge cases.
- **Test, then redo.** After passing tests, reimplement the core function without consulting your previous code.
- **Return values matter.** Count the characters actually printed, including spaces, zeros, prefixes, and signs.
- **Keep the mandatory project stable.** Add bonus features incrementally and check for regressions.

### How to use this file

Tick each box when you can explain the logic, implement the program, pass tests, and redo it without help. Save each practice program separately (for example, `ex01_count_digits.c`). The examples use **`␣` for a visible space**; actual output contains regular spaces.

**Progress:** 0 / 25 exercises completed.

---

## Phase 1 — Output & Width (Beginner)

**Objective:** Count digits and characters, print padding, and understand that `width` specifies a *minimum* field width.

- [ ] **01 — Count Digits.** Implement `int count_digits(int n);` to count decimal digits, excluding a minus sign. Test `42 → 2`, `0 → 1`, `-456 → 3`, `INT_MIN → 10` on a 32-bit `int`.
- [ ] **02 — Print Spaces.** Implement `int print_spaces(int count);` using `write`. Print exactly `count` spaces; return the number written. Example: `4 → ␣␣␣␣`.
- [ ] **03 — Number Width.** Print a nonnegative integer right-aligned in a minimum field width. Example: `width=6, n=42 → ␣␣␣␣42`. If the value is longer than the width, do **not** truncate it.
- [ ] **04 — Negative Width.** Extend the previous program to negative integers. Include `-` in the field length. Example: `width=6, n=-42 → ␣␣␣-42`.

**Checkpoint:** Explain why `%3d` with `12345` prints `12345`, without truncation.

## Phase 2 — Alignment & Zero Padding (Beginner → Intermediate)

**Objective:** Understand `-` and `0` and their interaction.

- [ ] **05 — Left Alignment.** Implement `print_left(int n, int width)` to print the number first and add trailing spaces. Example: `42, 6 → 42␣␣␣␣`.
- [ ] **06 — Zero Padding.** Use zeros instead of leading spaces for a positive integer. Example: `42, 6 → 000042`.
- [ ] **07 — Signed Zero Padding.** Handle negative values correctly: the sign appears before padding zeros. Example: `-42, 6 → -00042`.
- [ ] **08 — Flag Priority.** Practice the interaction of `-` and `0`. For numeric conversion, `-` overrides `0`. Example: `minus=1, zero=1, width=6, n=42 → 42␣␣␣␣`.

**Checkpoint:** Predict the results of `%06d`, `%-6d`, and `%-06d` with `42`.

## Phase 3 — Signs & Prefixes (Intermediate)

**Objective:** Implement `+`, space, and `#` while counting all printed characters.

- [ ] **09 — Plus Flag.** Show `+` on nonnegative signed integer conversions. Example: `42, plus=1 → +42`.
- [ ] **10 — Space Flag.** Add one leading space to a nonnegative signed integer if the space flag applies. Example: `42, space=1 → ␣42`.
- [ ] **11 — Sign Priority.** Combine signs, width, and zero padding. `+` overrides the space flag. Example: `plus=1, zero=1, width=6, n=42 → +00042`.
- [ ] **12 — Hash Prefix.** Add `0x` or `0X` to nonzero values formatted as hexadecimal when `#` is enabled. Example: `42` in lower hexadecimal with `#` → `0x2a`. Explore the zero-value case separately.

**Checkpoint:** Decide how many characters the sign or `0x` prefix contributes to minimum width.

## Phase 4 — Precision (Intermediate → Advanced)

**Objective:** Separate *precision* from *width*.

- [ ] **13 — Integer Precision.** Pad the digits with leading zeros up to the specified precision. Example: `n=42, precision=5 → 00042`.
- [ ] **14 — Zero Precision.** Handle integer zero with explicitly specified precision zero. Example: `%.0d` with `0` produces no digits; field width can still produce spaces.
- [ ] **15 — String Precision.** Limit the number of bytes printed from a string. Example: `"hello", precision=3 → hel`.
- [ ] **16 — Width + Precision.** Combine number width and precision. Example: `%8.5d` with `42 → ␣␣␣00042`. Remember: for integer conversions, an explicit precision disables the `0` flag.

**Checkpoint:** Explain the difference between `width=5, precision=3` and `width=3, precision=5`.

## Phase 5 — Parser Without Struct (Advanced)

**Objective:** Read formatting instructions *before* rendering the value, using ordinary variables and/or function parameters.

- [ ] **17 — Flag Scanner.** Scan repeated supported flags, update separate flag variables, and advance the index. Example: `%-+d → minus=1, plus=1`.
- [ ] **18 — Width Parser.** Read consecutive digits and accumulate the width: `width = width * 10 + (str[i] - '0');`. Example: `%120d → width=120`.
- [ ] **19 — Precision Parser.** Recognize `.` and subsequent digits; distinguish **no precision specified** from **explicit `.0`**. Example: `%.0d → precision_specified=1, precision=0`.
- [ ] **20 — Full Conversion Parser.** Parse flags, width, precision, and a conversion specifier, and leave the index at the correct place. Example: `%-08.3d` contains two flags, width 8, precision 3, and `d`.

**Checkpoint:** Scan `"hello %-+10.4d world"` and say where parsing starts, where it ends, and what values were captured.

## Phase 6 — Rendering Engine (Advanced)

**Objective:** Connect parsing to output without mixing the responsibilities too early.

- [ ] **21 — Formatting Pipeline.** Apply sign, numeric precision, field width, and alignment in the correct order. Example: `%+8.4d` with `42 → ␣␣␣+0042`.
- [ ] **22 — Conversion Dispatcher.** Dispatch `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`; preserve the mandatory behavior and correct return count. Only apply flags where they are meaningful and required by the 42 subject.
- [ ] **23 — Mini Printf.** Use `va_list`, `va_start`, `va_arg`, and `va_end` to process ordinary text and multiple conversions in one format string. Example: `mini_printf("A:%-6d B:%s", 42, "ok")`.

**Checkpoint:** Explain the responsibilities of the format scanner, conversion dispatcher, and rendering functions without reading code.

## Phase 7 — Final Challenge (42 Project)

**Objective:** Implement, validate, and polish your own bonus.

- [ ] **24 — Edge-Case Suite.** Write expected-output and return-value tests for zero, negative values, `INT_MIN`, zero precision, width less than value length, combined flags, and each mandatory conversion. Compare valid, defined cases against the system `printf`.
- [ ] **25 — Independent Implementation.** Integrate the bonus into your repository. Verify `make`, `make bonus`, clean/rebuild behavior, `-Wall -Wextra -Werror`, Norminette, memory safety, and mandatory regressions. Confirm exact file and Makefile rules against your own 42 subject.

---

## Concepts checklist

- [ ] Minimum field width and character counts
- [ ] Right and left alignment (`-`)
- [ ] Zero padding (`0`)
- [ ] Sign flags (`+` and space)
- [ ] Hexadecimal alternative form (`#`)
- [ ] Precision for numeric and string conversions (`.`)
- [ ] Flag interaction and precedence
- [ ] Decimal digit parsing and string indices
- [ ] Parsing versus rendering
- [ ] Variadic arguments (`va_list`)
- [ ] Return-value accounting, failure handling, and regression testing

## Suggested mini-program workflow

1. **Predict:** Write the expected output (make spaces visible as `␣`).
2. **Plan:** Describe the algorithm in plain language or pseudocode.
3. **Code:** Implement only the current task, initially without structs.
4. **Test:** Check normal inputs and edge cases; also verify the return value.
5. **Explain:** State why the algorithm works and what can go wrong.
6. **Redo:** Rebuild the key logic from scratch without looking at the earlier version.

## Starter exercise — #01 Count Digits

```c
int count_digits(int n);
```

**Constraints:** Don't use `printf`, `sprintf`, `itoa`, or string conversions inside the function. Handle `0`, negative numbers, and `INT_MIN` safely. The returned count excludes a leading `-` sign.

| Input | Expected return |
|---|---:|
| `42` | `2` |
| `12345` | `5` |
| `0` | `1` |
| `-456` | `3` |
| `-2147483648` | `10` (for 32-bit `int`) |

**First thinking prompt:** For `n = 12345`, what C operation can remove the last decimal digit in each iteration, without using a string?

---

### Completion criteria

The roadmap is complete when you can **design the parser, combine flags correctly, produce the expected bytes, count printed characters, and debug the bonus yourself**, rather than copying a finished `ft_printf` implementation.

**Note:** This roadmap is a training aid, not a substitute for the exact requirements of your current 42 subject. Some format combinations are outside the subject or have undefined/implementation-specific behavior in standard C; test and implement the combinations that your subject requires.
