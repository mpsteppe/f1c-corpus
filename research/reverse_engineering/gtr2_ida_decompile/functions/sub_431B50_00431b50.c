int __thiscall sub_431B50(int *this, int a2)
{
  void *v3; // eax
  void *v4; // eax
  int v5; // eax
  int v6; // eax
  void *v7; // eax
  int v8; // edi
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // edi
  int v13; // eax
  size_t v15; // [esp-8h] [ebp-4A8h]
  int v16; // [esp+10h] [ebp-490h] BYREF
  int v17; // [esp+14h] [ebp-48Ch] BYREF
  _BYTE v18[96]; // [esp+18h] [ebp-488h] BYREF
  _BYTE v19[512]; // [esp+78h] [ebp-428h] BYREF
  int v20; // [esp+278h] [ebp-228h]
  char v21; // [esp+27Ch] [ebp-224h]
  int v22; // [esp+284h] [ebp-21Ch]
  int v23; // [esp+288h] [ebp-218h]
  int v24; // [esp+28Ch] [ebp-214h]
  char Str[516]; // [esp+290h] [ebp-210h] BYREF
  int v26; // [esp+49Ch] [ebp-4h]

  sub_613B30(v18);
  memset(Str, 0, 0x200u);
  v3 = (void *)this[1];
  v26 = 0;
  v20 = 0;
  v24 = 0;
  v22 = 0;
  v23 = 0;
  v21 = 1;
  *this = 0;
  if ( v3 )
    j_j__free(v3);
  v4 = (void *)this[3];
  this[1] = 0;
  this[2] = 0;
  if ( v4 )
    j_j__free(v4);
  this[3] = 0;
  if ( (unsigned __int8)sub_614460(a2, 1) )
  {
    while ( sub_613DE0(Str, 512) )
    {
      if ( !sub_612EB0(v19) )
      {
        if ( strstr(Str, "[GEAR_RATIOS]") )
        {
          *this = 0;
          while ( sub_613DE0(Str, 512) )
          {
            v5 = sub_612EB0(v19);
            if ( v5 == 1 || v5 == 4 )
              break;
            if ( !v5 && sub_6133A0("ratio", (int)&v16, (int)&v17, 0, 0) )
              ++*this;
          }
        }
        else if ( strstr(Str, "[FINAL_DRIVE]") )
        {
          this[2] = 0;
          while ( sub_613DE0(Str, 512) )
          {
            v6 = sub_612EB0(v19);
            if ( v6 == 1 || v6 == 4 )
              break;
            if ( !v6 && sub_6133A0("ratio", (int)&v16, (int)&v17, 0, 0) )
              ++this[2];
          }
        }
      }
    }
    v7 = operator new(8 * *this);
    v15 = 8 * this[2];
    this[1] = (int)v7;
    this[3] = (int)operator new(v15);
    sub_613F20(v18);
    while ( sub_613DE0(Str, 512) )
    {
      if ( !sub_612EB0(v19) )
      {
        if ( strstr(Str, "[GEAR_RATIOS]") )
        {
          if ( sub_613DE0(Str, 512) )
          {
            v8 = 0;
            do
            {
              v9 = sub_612EB0(v19);
              if ( v9 == 1 || v9 == 4 )
                break;
              if ( !v9 && sub_6133A0("ratio", v8 + this[1], v8 + this[1] + 4, 0, 0) )
                v8 += 8;
            }
            while ( sub_613DE0(Str, 512) );
          }
          v10 = *this;
          v11 = this[1];
LABEL_48:
          sub_632C60(v11, v10);
          continue;
        }
        if ( strstr(Str, "[FINAL_DRIVE]") )
        {
          if ( sub_613DE0(Str, 512) )
          {
            v12 = 0;
            do
            {
              v13 = sub_612EB0(v19);
              if ( v13 == 1 || v13 == 4 )
                break;
              if ( !v13 )
              {
                sub_6133A0("bevel", (int)(this + 4), (int)(this + 5), 0, 0);
                if ( sub_6133A0("ratio", v12 + this[3], v12 + this[3] + 4, 0, 0) )
                  v12 += 8;
              }
            }
            while ( sub_613DE0(Str, 512) );
          }
          v10 = this[2];
          v11 = this[3];
          goto LABEL_48;
        }
      }
    }
    sub_613C30(v18);
  }
  v26 = -1;
  return sub_614140(v18);
}
