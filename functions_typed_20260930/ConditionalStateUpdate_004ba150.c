void __thiscall sub_4BA150(_DWORD *this)
{
  int *v1; // ecx
  float v2; // [esp+0h] [ebp-4h]

  if ( *this == 1 && !PackedFlagRead_9a00(this + 2) )
  {
    v2 = dbl_8AFEA0;
    CallWrapper_9870(v1, &dword_7D2E50, 0, v2);
  }
}

