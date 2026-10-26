int sub_588821(const char *a1, ...)
{
  int v1; // edi
  int v2; // ebx
  va_list va; // [esp+14h] [ebp+8h] BYREF

  va_start(va, a1);
  CriticalSectionEnter(1, &unk_5E6768);
  v1 = sub_58E41B(&unk_5E6768);
  v2 = sub_58D04D(&unk_5E6768, a1, va);
  ClearStructFieldsIfFlagSet(v1, &unk_5E6768);
  CriticalSectionLeave_c232(1, &unk_5E6768);
  return v2;
}
