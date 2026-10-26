// Function: FUN_0052e520 @ 0052e520
// Size (bytes): 15


void FUN_0052e520(void)

{
  code *pcVar1;
  
  (*(code *)PTR_FUN_005da714)(s___Halting_program_005da720);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


