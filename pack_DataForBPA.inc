void arinc429_pack_DataForBPA(const struct DataForBPA *o, uint32_t *arr, unsigned int *len)
{

uint32_t tmp_word;

arr[0] &= ~(0x3u << 8);
arr[0] |= (o->Mode & 0x3u) << 8;

arr[0] &= ~(0x1u << 10);
arr[0] |= (o->ARSQuery & 0x1u) << 10;

arr[0] &= ~(0xFFFFu << 11);
arr[0] |= (o->NumberARS & 0xFFFFu) << 11;

memcpy(&tmp_word, &o->Frequency, sizeof(tmp_word));

arr[1] &= ~(0x7FFFFFu << 8);
arr[1] |= (tmp_word & 0x7FFFFFu) << 8;

tmp_word >>= 23;

arr[2] &= ~(0x1FFu << 8);
arr[2] |= (tmp_word & 0x1FFu) << 8;

arr[0] &= ~(0x1u << 27);
arr[0] |= (o->sms_valid & 0x1u) << 27;

memcpy(&tmp_word, &o->sms, sizeof(tmp_word));

arr[3] &= ~(0x7FFFFFu << 8);
arr[3] |= (tmp_word & 0x7FFFFFu) << 8;

tmp_word >>= 23;

arr[2] &= ~(0x1FFu << 17);
arr[2] |= (tmp_word & 0x1FFu) << 17;

memcpy(&tmp_word, ((char *)&o->sms) + 4, sizeof(tmp_word));

arr[4] &= ~(0x7FFFFFu << 8);
arr[4] |= (tmp_word & 0x7FFFFFu) << 8;

tmp_word >>= 23;

arr[5] &= ~(0x1FFu << 8);
arr[5] |= (tmp_word & 0x1FFu) << 8;

arr[0] &= ~(0x3u << 28);
arr[0] |= (o->State & 0x3u) << 28;

memcpy(&tmp_word, &o->Checksum, sizeof(tmp_word));

arr[6] &= ~(0x7FFFFFu << 8);
arr[6] |= (tmp_word & 0x7FFFFFu) << 8;

tmp_word >>= 23;

arr[5] &= ~(0x1FFu << 17);
arr[5] |= (tmp_word & 0x1FFu) << 17;


arr[0] &= ~0xFFu;
arr[0] |= (1 & 0xFFu);

arr[1] &= ~0xFFu;
arr[1] |= (2 & 0xFFu);

arr[2] &= ~0xFFu;
arr[2] |= (3 & 0xFFu);

arr[3] &= ~0xFFu;
arr[3] |= (4 & 0xFFu);

arr[4] &= ~0xFFu;
arr[4] |= (5 & 0xFFu);

arr[5] &= ~0xFFu;
arr[5] |= (6 & 0xFFu);

arr[6] &= ~0xFFu;
arr[6] |= (7 & 0xFFu);

assert(*len >= 7);
*len = 7;
}

void arinc429_pack_DataForBPA_checksum(const struct DataForBPA *o, uint32_t *arr, unsigned int len)
{

uint32_t tmp_word;

assert(len >= 7);

memcpy(&tmp_word, &o->Checksum, sizeof(tmp_word));
arr[6] &= ~(0x7FFFFFu << 8);
arr[6] |= (tmp_word & 0x7FFFFFu) << 8;

tmp_word >>= 23;

arr[5] &= ~(0x1FFu << 17);
arr[5] |= (tmp_word & 0x1FFu) << 17;

}

