char __thiscall sub_4DA7E0(int *this, int *a2)
{
  unsigned int v2; // kr00_4
  __int32 v3; // edx
  __int32 v4; // edx
  void *v6; // edi
  int v7; // eax
  int v8; // eax
  int v9; // edx
  int v10; // eax
  __int32 v12[5]; // [esp+0h] [ebp-53Ch] BYREF
  int v13; // [esp+14h] [ebp-528h] BYREF
  int v14; // [esp+18h] [ebp-524h] BYREF
  int v15; // [esp+1Ch] [ebp-520h] BYREF
  int v16; // [esp+20h] [ebp-51Ch] BYREF
  int v17[64]; // [esp+24h] [ebp-518h] BYREF
  _BYTE v18[512]; // [esp+124h] [ebp-418h] BYREF
  int v19; // [esp+324h] [ebp-218h]
  char v20; // [esp+328h] [ebp-214h]
  int v21; // [esp+330h] [ebp-20Ch]
  int v22; // [esp+334h] [ebp-208h]
  int v23; // [esp+338h] [ebp-204h]
  _BYTE var200[516]; // [esp+33Ch] [ebp-200h] BYREF

  v6 = (void *)this[67];
  if ( v6 )
  {
    sub_4D38B0();
    j__free(v6);
  }
  this[67] = 0;
  sub_4DA470(this + 68);
  if ( a2[1] )
  {
    memset(v17, 0, sizeof(v17));
    memset(var200, 0, 0x200u);
    v12[0] = 511;
    v14 = 255;
    v13 = 255;
    v15 = 255;
    v16 = 255;
    v7 = *a2;
    v19 = 0;
    v23 = 0;
    v21 = 0;
    v22 = 0;
    v20 = 1;
    if ( (*(int (__thiscall **)(int *, _BYTE *, int))(v7 + 36))(a2, var200, 511) )
    {
      do
      {
        v8 = sub_612EB0(v18);
        if ( v8 )
        {
          if ( v8 == 2 )
            return 1;
        }
        else
        {
          sub_6133A0("TabWidth", (int)(this + 74), 0, 0, 0);
          sub_6133A0("TabHeight", (int)(this + 75), 0, 0, 0);
          sub_6133A0("TabSpaceHorizontal", (int)(this + 76), 0, 0, 0);
          sub_6133A0("TabSpaceVertical", (int)(this + 77), 0, 0, 0);
          sub_6134B0("RolloverPulseTime", (int)(this + 81), 0, 0, 0, 0, 0, 0, 0);
          sub_6134B0("TabFontScale", (int)(this + 82), 0, 0, 0, 0, 0, 0, 0);
          if ( sub_6133A0("ColorNotSelected_ARGB", (int)&v16, (int)&v15, (int)&v13, (int)&v14) )
          {
            v9 = v15;
            this[78] = v14 | ((v13 | ((v15 | (v16 << 8)) << 8)) << 8);
          }
          else if ( sub_6133A0("ColorSelected_ARGB", (int)&v16, (int)&v15, (int)&v13, (int)&v14) )
          {
            v9 = v14 | ((v13 | ((v15 | (v16 << 8)) << 8)) << 8);
            this[79] = v9;
          }
          else if ( sub_6133A0("ColorRollover_ARGB", (int)&v16, (int)&v15, (int)&v13, (int)&v14) )
          {
            v9 = v15;
            this[80] = v14 | ((v13 | ((v15 | (v16 << 8)) << 8)) << 8);
          }
          else if ( sub_6133A0("TabFontColorNotSelected", (int)&v16, (int)&v15, (int)&v13, (int)&v14) )
          {
            v9 = v15;
            this[83] = v14 | ((v13 | ((v15 | (v16 << 8)) << 8)) << 8);
          }
          else if ( sub_6133A0("TabFontColorSelected", (int)&v16, (int)&v15, (int)&v13, (int)&v14) )
          {
            v9 = v14 | ((v13 | ((v15 | (v16 << 8)) << 8)) << 8);
            this[84] = v9;
          }
          else if ( sub_6133A0("TabFontColorRollover", (int)&v16, (int)&v15, (int)&v13, (int)&v14) )
          {
            v9 = v15;
            this[85] = v14 | ((v13 | ((v15 | (v16 << 8)) << 8)) << 8);
          }
          else if ( sub_6131C0("Texture", (int)v17) )
          {
            sub_615860(v17);
          }
          else if ( sub_6131C0((char *)off_711740, (int)v17) && !this[67] )
          {
            this[67] = sub_4DA070((int)a2, (int)v17);
          }
        }
        v10 = *a2;
        v12[0] = v9;
        v2 = __readeflags();
        v3 = off_16C6D2C - (_UNKNOWN *)((char *)dword_16CBE3C + 1);
        __writeeflags(v2);
        v4 = _InterlockedExchange(v12, v3);
      }
      while ( (*(int (__fastcall **)(int *, __int32, _BYTE *, __int32))(v10 + 36))(a2, v4, var200, v12[0]) );
    }
  }
  return 1;
}
