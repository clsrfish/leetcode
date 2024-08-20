import logging

from pytest import Item


def pytest_runtest_call(item: Item):
    logging.info(item.nodeid + " starts")
