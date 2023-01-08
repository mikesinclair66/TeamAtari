import pandas as pd


def read_csv_file():
    x = pd.read_csv('data_group0.csv',sep = ',')
    # data_set = x.dropna()
    master_data_set_list = x.values.tolist()

    return master_data_set_list


def find_unique_shovel_payloads(shovel_id):
    all_payloads_shovel_one_set = set()
    all_payloads_shovel_one_string_set = set()
    payloads_float_set2 = set()

    master_data_set_list = read_csv_file()

    for line in master_data_set_list:
        if line[10] == shovel_id and "Hauling" in line[6]:
            all_payloads_shovel_one_set.add(line[7])

    for payload in all_payloads_shovel_one_set:
        string_payload = str(payload)
        all_payloads_shovel_one_string_set.add(string_payload)

    all_payloads_shovel_one_string_set.remove('nan')
    for payload in all_payloads_shovel_one_string_set:
        payloads_float_set2.add(float(payload))

    return payloads_float_set2


def calculate_total_shovel_payload(shovel_id):
    payloads_set = find_unique_shovel_payloads(shovel_id)
    total_payload_shovel_one_float = 0.0

    for value in payloads_set:
        total_payload_shovel_one_float += float(value)
    print(total_payload_shovel_one_float)


def find_unique_dump_ids_for_shovel(shovel_id):
    master_data_set_list = read_csv_file()
    unique_payouts_for_shovel = find_unique_shovel_payloads(shovel_id)
    uniq_dump_ids_for_shovel_set = set()

    for payload in unique_payouts_for_shovel:
        for line in master_data_set_list:
            if line[7] == payload and line[10] == shovel_id:
                uniq_dump_ids_for_shovel_set.add(line[11])

    return uniq_dump_ids_for_shovel_set


def find_dump_ids_per_payload(shovel_id):

    payload_dump_list = []
    master_data_set_list = read_csv_file()
    payload_set = find_unique_shovel_payloads(shovel_id)

    for payload in payload_set:
        for line in master_data_set_list:
            if line[7] == payload and line[10] == shovel_id:
                mini_list = [payload, line[11]]
                payload_dump_list.append(mini_list)
                break

    return payload_dump_list


def calculate_total_payload_per_shovel_dump(shovel_id):
    dump_ids_set = find_unique_dump_ids_for_shovel(shovel_id)
    payload_and_dump_ids = find_dump_ids_per_payload(shovel_id)

    print("Shovel ID: ", shovel_id)
    for dump_id in dump_ids_set:
        subtotal = 0.0
        for sub_list in payload_and_dump_ids:
            if sub_list[1] == dump_id:
                subtotal += sub_list[0]
        sub_string = "Dump ID %d payload subtotal is %f" % (dump_id, subtotal)
        print(sub_string)


def main():
    # master_list = read_csv_file()
    # unique_payloads = find_unique_shovel_payloads(1)
    # print(unique_payloads)
    # print(len(find_unique_shovel_payloads(1)))

    # calculate_total_shovel_payload(1)

    # shovel_dump_ids = find_unique_dump_ids_for_shovel(1)
    # print(shovel_dump_ids)
    #
    # dump_ids_per_payload = find_dump_ids_per_payload(1)
    # print(dump_ids_per_payload)
    # print(len(dump_ids_per_payload))

    calculate_total_payload_per_shovel_dump(1)

if __name__ == "__main__":
    main()
