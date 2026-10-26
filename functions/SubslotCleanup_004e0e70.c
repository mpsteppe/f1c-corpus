int __thiscall sub_4E0E70(char *this, int a2)
{
  int *v2; // edi
  int result; // eax

  v2 = (int *)&this[296 * a2];
  ConditionalResourceRelease(v2 + 81);
  VibrationStateMachine(a2, 0.0);
  v2 += 98;
  result = ConditionalResourceRelease(v2);
  if ( *v2 )
    return FlagFieldBitManipulation(0, 0, 0, 0);
  return result;
}
