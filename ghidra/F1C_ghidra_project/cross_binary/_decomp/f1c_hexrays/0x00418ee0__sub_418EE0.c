// f1c  0x00418ee0  size=468
int __thiscall sub_418EE0(_BYTE *this)
{
  int v1; // ebp
  int v2; // edi
  char *v3; // edx
  _DWORD *v4; // esi
  _DWORD *v5; // ebx
  int v6; // eax
  int v7; // ebp
  int v8; // eax
  int result; // eax
  int v10; // [esp+10h] [ebp-20h]
  int v11; // [esp+14h] [ebp-1Ch]
  int v12; // [esp+18h] [ebp-18h]
  int v13; // [esp+1Ch] [ebp-14h]
  char *i; // [esp+24h] [ebp-Ch]
  float v16; // [esp+28h] [ebp-8h]
  float v17; // [esp+2Ch] [ebp-4h]

  v1 = 0x7FFFFFFF;
  v2 = 0;
  v3 = (char *)((char *)dword_7C54F0 - this);
  v13 = -1;
  v12 = -1;
  v11 = 0x7FFFFFFF;
  v10 = 0x7FFFFFFF;
  v4 = &unk_5F0CF8;
  v5 = this;
  for ( i = (char *)((char *)dword_7C54F0 - this); ; v3 = i )
  {
    *v5 = 0;
    if ( dword_7D0410 == 2 )
      goto LABEL_28;
    if ( *(v4 - 1238) == -1 )
    {
      *v5 = -1;
      goto LABEL_28;
    }
    if ( dword_7C54E8 && dword_7C54E8 == *(_DWORD *)((char *)v5 + (_DWORD)v3) )
    {
      *v5 = 1;
      goto LABEL_28;
    }
    if ( *(_DWORD *)(dword_7C54E8 + 18592) == *(_DWORD *)(*(_DWORD *)((char *)v5 + (_DWORD)v3) + 18592) )
    {
      *v5 = 2;
      goto LABEL_28;
    }
    if ( dword_7D0410 != 4 )
      goto LABEL_28;
    v17 = (float)sub_41E890(v4);
    if ( (double)sub_41E840() * (1.0 - 0.1) <= v17 )
    {
      v16 = (float)sub_41E890(v4);
      if ( (double)sub_41E840() * (0.1 + 1.0) >= v16 && sub_4C2990(&unk_7D2DB0) >= 3 )
      {
        v6 = v4[60] - *(_DWORD *)(dword_7C54E8 + 18192);
        if ( v1 < 0 )
        {
          if ( v6 > 0 || v6 <= v1 )
            goto LABEL_21;
LABEL_20:
          v10 = v4[60] - *(_DWORD *)(dword_7C54E8 + 18192);
          v12 = v2;
          goto LABEL_21;
        }
        if ( v6 < v1 )
          goto LABEL_20;
      }
    }
LABEL_21:
    if ( !sub_41E890(v4) )
      goto LABEL_28;
    v7 = sub_41E890(v4);
    v8 = sub_41E840() - v7;
    if ( v11 >= 0 )
    {
      if ( v8 > v11 )
        goto LABEL_28;
LABEL_27:
      v11 = v8;
      v13 = v2;
      goto LABEL_28;
    }
    if ( v8 <= 0 && v8 > v11 )
      goto LABEL_27;
LABEL_28:
    v4 += 4656;
    ++v2;
    ++v5;
    if ( (int)v4 >= (int)dword_7C9AF8 )
      break;
    v1 = v10;
  }
  result = v12;
  if ( v12 < 0 )
  {
    result = v13;
    if ( v13 >= 0 )
      *(_DWORD *)&this[4 * v13] = 3;
  }
  else
  {
    *(_DWORD *)&this[4 * v12] = 3;
  }
  return result;
}
